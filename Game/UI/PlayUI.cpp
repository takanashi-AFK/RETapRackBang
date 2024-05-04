#include "PlayUI.h"
#include "CountDown.h"
#include "CrossHair.h"

PlayUI::PlayUI(GameObject* parent)
{
}

void PlayUI::Initialize()
{
	BaseImage_ = Image::Load("UI/PlayUI.png");
	assert(BaseImage_ >= 0);

	score_ = new Text;
	score_->Initialize("mininumberBlack.png", 32, 34, 15);

	transform_.position_.y = 0.55;
	transform_.scale_ = { 1.25,1.25,1.25 };
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

	score_->Draw(500, 50, g_Score);
}

void PlayUI::Release()
{
}
