#include "Player.h"
#include "../../Engine/GameObject.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/Model.h"
#include "../Gun/Gun.h"

Player::Player(GameObject* parent) :
	GameObject(parent, "Player")
{
}

void Player::Initialize()
{
	pModelHandle_ = Model::Load("Player/TestBird.fbx");
	assert(pModelHandle_ >= 0);
	Instantiate<Gun>(this);
}

void Player::Update()
{
	PlayerMove();
	TPSCam();
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
	XMVECTOR dir{};
	XMVECTOR sightLine = Camera::GetSightLine();
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
	XMVECTOR move = XMVector3Normalize(dir) * speed;

	//�v���C���[�̈ʒu�ɑ΂��āA��ō�����ړ��x�N�g���𑫂�
	XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + move);
}

void Player::TPSCam()
{
	//�}�E�X�̈ړ��ʂ��p�x�Ƃ��Ē~�ς���
	rotateAngle_.x += Input::GetMouseMove().x * sensitivity;
	rotateAngle_.y += Input::GetMouseMove().y * sensitivity;

	XMFLOAT3 center = transform_.position_;
	center.y = center.y + camYOutset;

	XMFLOAT3 camTarget{};
	XMFLOAT3 camPosition{};


	if (rotateAngle_.y < upperlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;


	if (rotateAngle_.y > lowerlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;

	/*Y����]*/ {

		//���ۂɂ͉��̃x�N�g���ŁAplayerToCamTarget�ł͂Ȃ��A�����ϐ�����T����
		XMVECTOR playerToCamTarget{ 0.f,0.f,1.f,0.f };
		//Y���ŉ���]�s����쐬�AplayerToCamTarget����]������
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(rotateAngle_.x));
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

	transform_.rotate_.x = rotateAngle_.y;
	transform_.rotate_.y = rotateAngle_.x;

	Camera::SetTarget(camTarget);
	Camera::SetPosition(camPosition);
}

