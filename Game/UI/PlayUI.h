#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"
#include "../../Engine/Image.h"
#include "../../GlobalValiable.h"

class PlayUI : public GameObject
{
private:
	//Text* time_;
	Text* score_;
	int BaseImage_;


public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayUI(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};