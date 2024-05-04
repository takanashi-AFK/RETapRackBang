#pragma once
#include "../../Engine/GameObject.h"
class Gun : public GameObject
{
private:
	int gunModelHandle_;
	bool canShot_;
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

	void SetCanShot(bool _canShot);
};