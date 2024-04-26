#pragma once
#include "../../Engine/GameObject.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
private:
	XMVECTOR playerVec_;
	int pModelHandle_;

	const float speed = 0.5f;
	const int camYOutset = 4;
	const float camZOutset = 0.5f;
	const float camXOutset = 90.f;
	const float camAngleOutset = -30.f;
	const float upperlimit = -30.f;
	const float lowerlimit = 50.f;
	const float distance = 10.f;

	//カメラ関連
	const float sensitivity = 0.05f;
	XMFLOAT3 rotateAngle_;
	XMFLOAT3 newCenter_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// プレイヤーの移動
	/// </summary>
	void PlayerMove();

	void TPSCam();

	XMVECTOR GetPlayerVector() { return playerVec_; }
};