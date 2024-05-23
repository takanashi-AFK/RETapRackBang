#include "ScoreManager.h"

namespace ScoreManager{
	int score_;
	int numOfShot_;
	int numOfHit_;
}

void ScoreManager::AddNumOfShot()
{
	numOfShot_++;
}

void ScoreManager::AddNumOfHit()
{
	numOfHit_++;
}

int ScoreManager::GetScore()
{
	return score_;
}

int ScoreManager::GetNumOfShot()
{
	return numOfShot_;
}

int ScoreManager::GetNumOfHit()
{
	return numOfHit_;
}

float ScoreManager::GetAccuracy()
{
	if(numOfHit_ == 0 || numOfShot_ == 0)
		return 0;
	else
	return (float)numOfHit_/numOfShot_*100;
}

void ScoreManager::Reset()
{
		score_ = 0;
	numOfShot_ = 0;
	numOfHit_  = 0;
}
