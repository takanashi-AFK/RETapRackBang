#include "Player.h"
#include "../../Engine/GameObject.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/Model.h"
#include "../Gun/Gun.h"

namespace {
	const float speed = 0.5f;
	const int camYOutset = 4;
	const float camZOutset = 0.5f;
	const float camXOutset = 90.f;
	const float camAngleOutset = -30.f;
	const float upperlimit = -30.f;
	const float lowerlimit = 50.f;
	const float distance = 10.f;
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
	//プレイヤーのモデルを読み込む
	pModelHandle_ = Model::Load("Player/TestBird.fbx");
	assert(pModelHandle_ >= 0);

	//銃のインスタンスを生成
	pGun = Instantiate<Gun>(this);
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
	if (canMove_) {
	XMVECTOR dir{};
	//視線ベクトルを取得
	XMVECTOR sightLine = Camera::GetSightLine();
	//視線ベクトルのY軸の値を0にし、正規化
	sightLine = XMVectorSetY(sightLine, 0);
	sightLine = XMVector3Normalize(sightLine);
	float rotationAngle = 0.0f;

	//Wが押されたら
	if (Input::IsKey(DIK_W)) {
		//方向ベクトルに対して視線の方向を足す
		dir += sightLine;
	}

	if (Input::IsKey(DIK_A)) {
		//方向ベクトルに対して-90°をラジアン変換したものをY軸で回したものを足す
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(-camXOutset)));
	}

	if (Input::IsKey(DIK_S)) {
		dir += -sightLine;
	}

	if (Input::IsKey(DIK_D)) {
		dir += XMVector3Transform(sightLine, XMMatrixRotationY(XMConvertToRadians(camXOutset)));
	}

	transform_.rotate_.y = rotationAngle;

	//最終の移動ベクトルに対して、方向ベクトルをspeedで伸ばしたものを代入
	XMVECTOR move = XMVector3Normalize(dir) * speed;

	//プレイヤーの位置に対して、上で作った移動ベクトルを足す
	XMStoreFloat3(&transform_.position_, XMLoadFloat3(&transform_.position_) + move);
	}
}

void Player::TPSCam()
{
	//マウスの移動量を角度として蓄積する
	rotateAngle_.x += Input::GetMouseMove().x * sensitivity;
	rotateAngle_.y += Input::GetMouseMove().y * sensitivity;

	//カメラの中心点をプレイヤーの位置に仮設定
	XMFLOAT3 center = transform_.position_;
	//カメラの中心点を少し上にずらす
	center.y = center.y + camYOutset;

	XMFLOAT3 camTarget{};
	XMFLOAT3 camPosition{};

	//Y軸の回転角度を制限
	if (rotateAngle_.y < upperlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;
	if (rotateAngle_.y > lowerlimit)rotateAngle_.y -= Input::GetMouseMove().y * sensitivity;

	/*Y軸回転*/ {

		//実際には仮のベクトルで、playerToCamTargetではない、いい変数名を探そう
		XMVECTOR playerToCamTarget{ 0.f,0.f,1.f,0.f };
		//Y軸で回る回転行列を作成、playerToCamTargetを回転させる
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(rotateAngle_.x));
		//プレイヤーからカメラのターゲットに向かうベクトルを生成
		playerToCamTarget = XMVector3Transform(playerToCamTarget, rotY);
		playerToCamTarget *= distance;

		//原点からplayerPosに向かうベクトル
		XMVECTOR originToPlayer = XMLoadFloat3(&center);
		//原点からCamTargetに向かうベクトル
		XMVECTOR originToCamTarget = playerToCamTarget + originToPlayer;

		//プレイヤーからターゲットに向かう方向ベクトルの逆ベクトルをとり、
		//プレイヤーからポジションへのベクトルを生成、回転
		XMVECTOR playerToCamPosition = -playerToCamTarget;
		playerToCamPosition = XMVector3Transform(playerToCamPosition, XMMatrixRotationY(XMConvertToRadians(camAngleOutset)));

		//原点からカメラのポジションに向かうベクトルを生成
		XMVECTOR originToCamPosition = originToPlayer + playerToCamPosition;

		//カメラのターゲットを作成
		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);
	}

	/*X軸回転*/ {
		// 新しい中心点を作成
		XMStoreFloat3(&newCenter_, (XMLoadFloat3(&camPosition) + XMLoadFloat3(&camTarget)) * camZOutset);

		// 回転の軸を作成
		XMVECTOR rotateAxis = XMVector3Normalize(XMLoadFloat3(&newCenter_) - XMLoadFloat3(&center));

		// 回転行列を作成
		XMMATRIX rotAxisMat = XMMatrixRotationAxis(rotateAxis, XMConvertToRadians(rotateAngle_.y));

		// 回転させるベクトルを用意
		XMVECTOR newCenterToCamTarget = XMLoadFloat3(&camTarget) - XMLoadFloat3(&newCenter_);

		// 回転させる
		newCenterToCamTarget = XMVector3Transform(newCenterToCamTarget, rotAxisMat);

		// 逆ベクトルを作成
		XMVECTOR newCenterToCamPosition = -newCenterToCamTarget;

		// 原点からのベクトルを作成
		XMVECTOR originToCamTarget = XMLoadFloat3(&newCenter_) + newCenterToCamTarget;
		XMVECTOR originToCamPosition = XMLoadFloat3(&newCenter_) + newCenterToCamPosition;

		XMStoreFloat3(&camTarget, originToCamTarget);
		XMStoreFloat3(&camPosition, originToCamPosition);
	}

	//カメラの視線とプレイヤーモデルの向きを合わせる
	transform_.rotate_.x = rotateAngle_.y;
	transform_.rotate_.y = rotateAngle_.x;

	Camera::SetTarget(camTarget);
	Camera::SetPosition(camPosition);
}

void Player::SetCanMove(bool _canMove)
{
	canMove_ = _canMove;
}

