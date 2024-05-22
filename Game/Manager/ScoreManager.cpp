#include "ScoreManager.h"

void ScoreManager::AddScore()
{
	score_++;
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
	return numOfShot_/numOfHit_;
}

void ScoreManager::Reset()
{
		score_ = 0;
	numOfShot_ = 0;
	numOfHit_  = 0;
}
