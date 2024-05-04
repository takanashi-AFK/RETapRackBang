#include "PlayScene.h"
#include "../../Game/Stage/SimpleStage.h"
#include "../../Game/Player/Player.h"
#include "../../Game/Stage/SkySphere.h"
#include "../../Game/Target/TargetManager.h"
#include "../../Game/UI/Timer.h"
#include "../UI/PlayUI.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{

	g_Score = 0;
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	Instantiate<TargetManager>(this);
	Instantiate<PlayUI>(this);
}

//更新
void PlayScene::Update()
{
	static int frame;
	SetCursorPos(screenWidth/2,screenHeight/2);
	Timer* pTimer = (Timer*)FindObject("Timer");
	if (pTimer->GetTimerEnd()) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_RESULT, TID_BLACKOUT, 0.5f);
	}

	frame++;
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}


