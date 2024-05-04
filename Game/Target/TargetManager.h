#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/Direct3D.h"
#include "SphereTarget.h"
#include <array>
//テストシーンを管理するクラス

const int PLACE_SIZE{ 4 };
const int TARGET_NUM{ 3 };
const float PLACE_OUTSET{ 3.f };
const float PLACE_HEIGHT_OUTSET{ 5 };
const float PLACE_DEPTH{ 35 };

class TargetManager : public GameObject
{
private:
	std::array<SphereTarget*, TARGET_NUM> pSp;
	XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
	XMFLOAT3 brokenTargetPos_;
	int xPos_, yPos_;
	std::array<XMFLOAT3, TARGET_NUM> previousPos_;

	int brokenTarget_;
	bool isTargetBroken_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TargetManager(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// ターゲットが弾に当たったら呼ばれる関数
	/// </summary>
	/// <param name="pos">破壊されたターゲットの位置</param>
	void OnAction(XMFLOAT3 pos)override;

	/// <summary>
	/// ターゲットの初期生成
	/// </summary>
	void GenerateTarget();

	/// <summary>
	/// ターゲットの再生成
	/// </summary>
	void ReGenerateTarget();

	std::array<SphereTarget*, 3> GetSphereTarget() { return pSp; }

};
