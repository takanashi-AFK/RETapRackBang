#include "ResultScene.h"

ResultScene::ResultScene(GameObject* parent):
	GameObject(parent,"ResultScene")
{
}

void ResultScene::Initialize()
{
}

void ResultScene::Update()
{

	if (Input::IsKeyDown(DIK_SPACE)) {
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
}

void ResultScene::Draw()
{
}

void ResultScene::Release()
{
}
