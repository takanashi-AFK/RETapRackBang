#include "TestScene.h"
#include "Game/Stage/SimpleStage.h"
#include "Game/Player/Player.h"
#include "Game/UI/CrossHair.h"
#include "Game/Stage/SkySphere.h"
#include "Game/Target/TargetManager.h"

//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	Instantiate<TargetManager>(this);
	Instantiate<CrossHair>(this);
}

//更新
void TestScene::Update()
{
	SetCursorPos(screenWidth/2,screenHeight/2);
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}


