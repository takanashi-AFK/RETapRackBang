#include "Player.h"
#include "../../Engine/GameObject.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/Model.h"
#include "../Gun/Gun.h"
#include "../../Engine/ImGui/imgui.h"
#include "../Stage/SimpleStage.h"

namespace {
	const float SPEED = 0.5f;
	const int camYOutset = 4;
	const float camZOutset = 0.5f;
	const float camXOutset = 90.f;
	const float camAngleOutset = -30.f;
	const float upperlimit = -30.f;
	const float lowerlimit = 50.f;
	const float distance = 10.f;
	const XMFLOAT3 PLAYER_MODEL_SIZE = { 1.0f,1.0f,1.0f };
}

Player::Player(GameObject* parent) :
	GameObject(parent, "Player"),
	newCenter_{},
	pModelHandle_(-1),
	playerVec_{},
	rotateAngle_{},
	canMove_(true),
	pGun(nullptr)
{
}

void Player::Initialize()
{
	//�v���C���[�̃��f����ǂݍ���
	pModelHandle_ = Model::Load("Player/TestBird.fbx");
	assert(pModelHandle_ >= 0);

	//�e�̃C���X�^���X�𐶐�
	pGun = Instantiate<Gun>(this);
	
}

void Player::Update()
{
	// PlayerMove();
	TPSCam();

	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");   
	int hGroundModel = pStage->GetModelHandle();  


	{
		RayCastData downRayData;
		downRayData.start = transform_.position_;   // ���C�̔��ˈʒu
		downRayData.dir = XMFLOAT3(0, -1, 0);       // ���C�̕����i�������j
		Model::RayCast(hGroundModel, &downRayData); // ���C�𔭎�
		// ������
		if (downRayData.dist < 0.5f) {
			transform_.position_.y -= downRayData.dist;
		}

		RayCastData rightRayData;
		rightRayData.start = transform_.position_;  // ���C�̔��ˈʒu
		rightRayData.dir = XMFLOAT3(1, 0, 0);       // ���C�̕����i�E�����j
		Model::RayCast(hGroundModel, &rightRayData); // ���C�𔭎�
		// �E����
		if (rightRayData.dist < 0.5f) {
			XMVECTOR length = { (PLAYER_MODEL_SIZE.x / 2) - std::abs(rightRayData.dist),0,0 };
			XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) - length);
		}

		RayCastData leftRayData;
		leftRayData.start = transform_.position_;   // ���C�̔��ˈʒu
		leftRayData.dir = XMFLOAT3(-1, 0, 0);       // ���C�̕����i�������j
		Model::RayCast(hGroundModel, &leftRayData); // ���C�𔭎�
		// ������
		if (leftRayData.dist < 0.5f) {
			XMVECTOR length = { (PLAYER_MODEL_SIZE.x / 2) - std::abs(leftRayData.dist),0,0 };
			XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + length);
		}

		RayCastData frontRayData;
		frontRayData.start = transform_.position_;   // ���C�̔��ˈʒu
		frontRayData.dir = XMFLOAT3(0, 0, 1);        // ���C�̕����i�������j
		Model::RayCast(hGroundModel, &frontRayData); // ���C�𔭎�

		// ������
		if (frontRayData.dist < 0.5f) {
			XMVECTOR length = {0,0,(PLAYER_MODEL_SIZE.z / 2) + std::abs(frontRayData.dist) };
			XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) - length);
		}

		RayCastData backRayData;
		backRayData.start = transform_.position_;   // ���C�̔��ˈʒu
		backRayData.dir = XMFLOAT3(0, 0, -1);       // ���C�̕����i�������j
		Model::RayCast(hGroundModel, &backRayData); // ���C�𔭎�
		// ��O����
		if (backRayData.dist < 0.5f) {
			XMVECTOR length = { 0,0, (PLAYER_MODEL_SIZE.z / 2) - std::abs(backRayData.dist) };
			XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + length);
		}
		
	}
	
}

void Player::Draw()
{
	Model::SetTransform(pModelHandle_, transform_);
	Model::Draw(pModelHandle_);
}

void Player::Release()
{
}

void Player::PlayerMove()
{
	if (canMove_) {
	XMVECTOR dir{};
	//�����x�N�g�����擾
	XMVECTOR sightLine = Camera::GetSightLine();
	//�����x�N�g����Y���̒l��0�ɂ��A���K��
	sightLine = XMVectorSetY(sightLine, 0);
	sightLine = XMVector3Normalize(sightLine);
	float rotationAngle = 0.0f;

	//W�������ꂽ��
	if (Input::IsKey(DIK_W)) {
		//�����x�N�g���ɑ΂��Ď����̕����𑫂�
		dir += sightLine;
	}

	if (Input::IsKey(DIK_A)) {
		//�����x�N�g���ɑ΂���-90�������W�A���ϊ��������̂�Y���ŉ񂵂����̂𑫂�
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(-camXOutset)));
	}

	if (Input::IsKey(DIK_S)) {
		dir += -sightLine;
	}

	if (Input::IsKey(DIK_D)) {
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(camXOutset)));
	}

	transform_.rotate_.y = rotationAngle;

	//�ŏI�̈ړ��x�N�g���ɑ΂��āA�����x�N�g����speed�ŐL�΂������̂���
	XMVECTOR move = XMVector3Normalize(dir) * SPEED;

	//�v���C���[�̈ʒu�ɑ΂��āA��ō�����ړ��x�N�g���𑫂�
	XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + move);
	}
}

void Player::TPSCam()
{
	//�}�E�X�̈ړ��ʂ��p�x�Ƃ��Ē~�ς���
	rotateAngle_.x += Input::GetMouseMove().x * sensitivity;
	rotateAngle_.y += Input::GetMouseMove().y * sensitivity;

	//�J�����̒��S�_���v���C���[�̈ʒu�ɉ��ݒ�
	XMFLOAT3 center = transform_.position_;
	//�J�����̒��S�_��������ɂ��炷
	center.y = center.y + camYOutset;

	XMFLOAT3 camTarget{};
	XMFLOAT3 camPosition{};

	//X���̉�]�p�x�𐧌�
	if (rotateAngle_.y < upperlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;
	if (rotateAngle_.y > lowerlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;

	/*Y����]*/ {

		//���ۂɂ͉��̃x�N�g���ŁAplayerToCamTarget�ł͂Ȃ��A�����ϐ�����T����
		XMVECTOR playerToCamTarget{ 0.f,0.f,1.f,0.f };
		//Y���ŉ���]�s����쐬�AplayerToCamTarget����]������
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(rotateAngle_.x));
		//�v���C���[����J�����̃^�[�Q�b�g�Ɍ������x�N�g���𐶐�
		playerToCamTarget = XMVector3Transform(playerToCamTarget, rotY);
		playerToCamTarget *= distance;

		//���_����playerPos�Ɍ������x�N�g��
		XMVECTOR originToPlayer = XMLoadFloat3(&center);
		//���_����CamTarget�Ɍ������x�N�g��
		XMVECTOR originToCamTarget = playerToCamTarget + originToPlayer;

		//�v���C���[����^�[�Q�b�g�Ɍ����������x�N�g���̋t�x�N�g�����Ƃ�A
		//�v���C���[����|�W�V�����ւ̃x�N�g���𐶐��A��]
		XMVECTOR playerToCamPosition = -playerToCamTarget;
		playerToCamPosition = XMVector3Transform(playerToCamPosition, XMMatrixRotationY(XMConvertToRadians(camAngleOutset)));

		//���_����J�����̃|�W�V�����Ɍ������x�N�g���𐶐�
		XMVECTOR originToCamPosition = originToPlayer + playerToCamPosition;

		//�J�����̃^�[�Q�b�g���쐬
		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);
	}

	/*X����]*/ {
		// �V�������S�_���쐬
		XMStoreFloat3(&newCenter_, (XMLoadFloat3(&camPosition) + XMLoadFloat3(&camTarget)) * camZOutset);

		// ��]�̎����쐬
		XMVECTOR rotateAxis = XMVector3Normalize(XMLoadFloat3(&newCenter_) - XMLoadFloat3(&center));

		// ��]�s����쐬
		XMMATRIX rotAxisMat = XMMatrixRotationAxis(rotateAxis, XMConvertToRadians(rotateAngle_.y));

		// ��]������x�N�g����p��
		XMVECTOR newCenterToCamTarget = XMLoadFloat3(&camTarget) - XMLoadFloat3(&newCenter_);

		// ��]������
		newCenterToCamTarget = XMVector3Transform(newCenterToCamTarget, rotAxisMat);

		// �t�x�N�g�����쐬
		XMVECTOR newCenterToCamPosition = -newCenterToCamTarget;

		// ���_����̃x�N�g�����쐬
		XMVECTOR originToCamTarget = XMLoadFloat3(&newCenter_) + newCenterToCamTarget;
		XMVECTOR originToCamPosition = XMLoadFloat3(&newCenter_) + newCenterToCamPosition;

		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);
	}

	//�J�����̎����ƃv���C���[���f���̌��������킹��
	transform_.rotate_.x = rotateAngle_.y;
	transform_.rotate_.y = rotateAngle_.x;

	Camera::SetTarget(camTarget);
	Camera::SetPosition(camPosition);
}

void Player::SetCanMove(bool _canMove)
{
	canMove_ = _canMove;
}

