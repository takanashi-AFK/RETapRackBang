#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/VFX.h"

class Gun : public GameObject
{
private:
	int gunModelHandle_;
	bool canShot_;
	EmitterData shotEffect_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Gun(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// 射撃可能かどうかを設定
	/// </summary>
	/// <param name="_canShot">射撃可能 = true</param>
	void SetCanShot(bool _canShot);

	/// <summary>
	/// 射撃エフェクトの設定
	/// </summary>
	void ShotEffect();

};