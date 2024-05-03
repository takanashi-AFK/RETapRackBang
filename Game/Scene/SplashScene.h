#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/Transition.h"

class SplashScene : public GameObject
{
private:
	int splashImageHandle_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	SplashScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};