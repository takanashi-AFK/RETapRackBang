#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Engine/Input.h"
#include "../../Engine/SceneManager.h"

class TitleScene : public GameObject
{
private:
	int titleImageHandle_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};