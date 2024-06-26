#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/Direct3D.h"
//テストシーンを管理するクラス
class CrossHair : public GameObject
{
private:
	int crosshairImage_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CrossHair(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};
