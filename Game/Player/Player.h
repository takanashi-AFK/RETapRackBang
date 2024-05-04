#pragma once
#include "../../Engine/GameObject.h"
class Gun;
//テストシーンを管理するクラス
class Player : public GameObject
{
private:
	XMVECTOR playerVec_;
	int pModelHandle_;
	bool canMove_;
	Gun* pGun;

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

	void SetCanMove(bool _canMove);

	XMVECTOR GetPlayerVector() { return playerVec_; }
};