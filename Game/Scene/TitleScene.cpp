#include "TitleScene.h"

TitleScene::TitleScene(GameObject* parent)
{
}

void TitleScene::Initialize()
{
	//画像データのロード
	titleImageHandle_ = Image::Load("Scene/TitleImage/Title.png");
	assert(titleImageHandle_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(titleImageHandle_, transform_);
	Image::Draw(titleImageHandle_);
}

void TitleScene::Release()
{
}
