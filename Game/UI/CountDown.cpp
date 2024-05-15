#include "CountDown.h"
#include "../Player/Player.h"
#include "../UI/Timer.h"
#include "../Gun/Gun.h"
CountDown::CountDown(GameObject* parent) :
	GameObject(parent, "CountDown"),
	state(THREE),
	frame(0)
{
}

void CountDown::Initialize()
{
	for (int i = 0; i < 4; i++) {
		countImage_[i] = Image::Load("Scene/PlayImage/" + std::to_string(i + 1) + ".png");
		assert(countImage_[i] >= 0);
	}
	pTimer_ = Instantiate<Timer>(this);
	pTimer_->SetTime(20);

	pPlayer = (Player*)FindObject("Player");
	pPlayer->SetCanMove(false);

	pGun = (Gun*)FindObject("Gun");
	pGun->SetCanShot(false);
}

void CountDown::Update()
{
	if (frame < 60)
		state = THREE;
	else if (frame > 61 && frame < 120)
		state = TWO;
	else if (frame > 121 && frame < 180)
		state = ONE;
	else if (frame > 181 && frame < 210)
		state = START;
	else if (frame < 211)
		state = END;
	frame++;

}

void CountDown::Draw()
{
	switch (state)
	{
	case THREE:
		Image::SetTransform(countImage_[2], transform_);
		Image::Draw(countImage_[2]);
		break;
	case TWO:
		Image::SetTransform(countImage_[1], transform_);
		Image::Draw(countImage_[1]);
		break;

	case ONE:
		Image::SetTransform(countImage_[0], transform_);
		Image::Draw(countImage_[0]);
		break;

	case START:
		Image::SetTransform(countImage_[3], transform_);
		Image::Draw(countImage_[3]);
		//pPlayer->SetCanMove(true);
		pGun->SetCanShot(true);
		pTimer_->Start();
		break;
	}


}

void CountDown::Release()
{
}



