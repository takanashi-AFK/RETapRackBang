#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Engine/Input.h"
#include "../../Engine/SceneManager.h"
#include "../Manager/SoundManager.h"
class TitleScene : public GameObject
{
private:
	int titleImageHandle_;
	int pressSpaceImageHandle_;

	bool incleasing_;
	int opacity_;
	Transform spaceKeyTrans_;
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