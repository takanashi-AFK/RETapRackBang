#include "TitleScene.h"

namespace 
{
	const int OPACITY_INCLEASE = 5;
	const int OPACITY_MAX = 255;
}

TitleScene::TitleScene(GameObject* parent):
	GameObject(parent,"TitleScene"),
	titleImageHandle_(-1),
	pressSpaceImageHandle_(-1),
	opacity_(0),
	incleasing_(true)
{
}

void TitleScene::Initialize()
{
	//画像データのロード
	titleImageHandle_ = Image::Load("Scene/TitleImage/TitleImage.png");
	assert(titleImageHandle_ >= 0);

	pressSpaceImageHandle_ = Image::Load("Scene/TitleImage/PressSpaceKey.png");
	assert(pressSpaceImageHandle_ >= 0);

	spaceKeyTrans_.position_ = XMFLOAT3(0, -0.75, 0);
	ShowCursor(true);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SoundManager::PlayConfirmSound();
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY, TID_BLACKOUT, 0.5f);
	}
	
	if (incleasing_) {
		opacity_ += OPACITY_INCLEASE;
		if (opacity_ >= OPACITY_MAX)incleasing_ = false;
	}
	else {
		opacity_ -= OPACITY_INCLEASE;
		if (opacity_ <= 0)incleasing_ = true;
	}
	Image::SetAlpha(pressSpaceImageHandle_, opacity_);
}

void TitleScene::Draw()
{
	Image::SetTransform(titleImageHandle_, transform_);
	Image::Draw(titleImageHandle_);

	Image::SetTransform(pressSpaceImageHandle_, spaceKeyTrans_);
	Image::Draw(pressSpaceImageHandle_);

}

void TitleScene::Release()
{
}
