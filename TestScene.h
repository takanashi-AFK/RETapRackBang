#pragma once
#include "Engine/GameObject.h"
#include "Game/Target/SphereTarget.h"
#include <array>
//テストシーンを管理するクラス

const int PLACE_SIZE{ 4 };
const int TARGET_NUM{ 3 };
const float PLACE_OUTSET{ 3.f };
const float PLACE_HEIGHT_OUTSET{ 5 };
const float PLACE_DEPTH{ 35 };

class TestScene : public GameObject
{
private:
	SphereTarget* pSp[9];
	XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
	std::array<XMFLOAT3, 3> previousPos_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TestScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void GenerateSphereTarget();
};