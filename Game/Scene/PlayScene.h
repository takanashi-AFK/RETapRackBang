#pragma once
#include "../../Engine/GameObject.h"
#include "../../Game/Target/SphereTarget.h"
#include <array>
//テストシーンを管理するクラス
class Timer;

class PlayScene : public GameObject
{
private:
	int screenWidth;		//スクリーンの幅
	int screenHeight;	//スクリーンの高さ
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};