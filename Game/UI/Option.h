#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"

class Option : public GameObject
{
private:
	int optionImage_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Option(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};