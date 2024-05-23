#include "ResultScene.h"
#include "../../Engine/Image.h"
#include "../Manager/ScoreManager.h"


ResultScene::ResultScene(GameObject* parent):
	GameObject(parent,"ResultScene"),
	resultImageHandle_(-1),
	score_(nullptr)
{
}

void ResultScene::Initialize()
{
	resultImageHandle_ = Image::Load("Scene/ResultImage/Result.png");
	assert(resultImageHandle_ >= 0);


	score_ = new Text;
	score_->Initialize("number.png", 64, 68, 15);
}

void ResultScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SoundManager::PlayConfirmSound();
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
}

void ResultScene::Draw()
{
	Image::SetTransform(resultImageHandle_, transform_);
	Image::Draw(resultImageHandle_);

	score_->Draw(500, 300, ScoreManager::GetScore());
}

void ResultScene::Release()
{
}
