#include "PlayUI.h"
#include "CountDown.h"
#include "CrossHair.h"
#include "../Manager/ScoreManager.h"
PlayUI::PlayUI(GameObject* parent)
{
}

void PlayUI::Initialize()
{
	BaseImage_ = Image::Load("UI/PlayUI.png");
	assert(BaseImage_ >= 0);

	score_ = new Text;
	score_->Initialize("mininumberBlack.png", 32, 34, 15);
	
	accuracy_ = new Text;
	accuracy_->Initialize("mininumberBlack.png", 32, 34, 15);

	Instantiate<CountDown>(this);
	Instantiate<CrossHair>(this);
}

void PlayUI::Update()
{
}

void PlayUI::Draw()
{
	Image::SetTransform(BaseImage_, transform_);
	Image::Draw(BaseImage_);

	score_->Draw(500, 50, ScoreManager::GetNumOfHit());
	accuracy_->Draw(800, 50, ScoreManager::GetAccuracy());
}

void PlayUI::Release()
{
}
