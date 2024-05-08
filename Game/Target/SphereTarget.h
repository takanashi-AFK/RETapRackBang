#pragma once
#include"../../Engine/GameObject.h"
#include"../../Engine/SphereCollider.h"
#include "../../Engine/VFX.h"

class SphereTarget:public GameObject
{
private:
	int targetModelHandle_;
	EmitterData bulletHit_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SphereTarget(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//衝突したら
	void OnAction()override;

	//モデルハンドルの取得
	int GetModelHandle() {return targetModelHandle_; }

	//弾が当たった時のエフェクトの設定
	void InitBulletHitEff();
};

