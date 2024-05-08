#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/Input.h"
#include "../../Engine/Text.h"
#include "../../GlobalValiable.h"
#include "../Manager/SoundManager.h"

class ResultScene : public GameObject
{
private:
	int resultImageHandle_;
	Text* score_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	ResultScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};