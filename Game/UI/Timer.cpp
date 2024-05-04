#include "Timer.h"

Timer::Timer(GameObject* parent):
	GameObject(parent,"Timer"),
	currentTime_{},
	countTime_{}
{
}

void Timer::Initialize()
{
	time_ = new Text;
	time_->Initialize("mininumberBlack.png", 32, 34, 15);


}

void Timer::Update()
{
	if (isCount_) {

		currentTime_++;

		if (currentTime_ > countTime_) {
			isTimerEnd_ = true;
		}
	}
		
}

void Timer::Draw()
{
	time_->Draw(625, 50, countTime_/60 - (currentTime_ / 60));
}

void Timer::Release()
{
}

void Timer::Start()
{
	isCount_ = true;
	currentTime_ = 0;
}

void Timer::Stop()
{
	isCount_ = false;
}

bool Timer::GetTimerEnd()
{
	return isTimerEnd_;
}

void Timer::SetTime(int _time)
{
	countTime_ = _time*60;
}
