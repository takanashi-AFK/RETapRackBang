#include "MenuScene.h"


MenuScene::MenuScene(GameObject* parent):
	GameObject(parent, "MenuScene"),
	menuImageHandle_(-1)
{
}

void MenuScene::Initialize()
{
	//画像データのロード
	menuImageHandle_ = Image::Load("Scene/MenuImage/Menu.png");
	assert(menuImageHandle_ >= 0);

}

void MenuScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY, TID_BLACKOUT, 0.5f);
	}

}

void MenuScene::Draw()
{
	Image::SetTransform(menuImageHandle_, transform_);
	Image::Draw(menuImageHandle_);
}

void MenuScene::Release()
{
}
