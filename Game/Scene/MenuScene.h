#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
class MenuScene : public GameObject
{
private:
	int menuImageHandle_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	MenuScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};