#pragma once
namespace ScoreManager
{

	int score_;
	int numOfShot_;
	int numOfHit_;


	void AddScore();
	void AddNumOfShot();
	void AddNumOfHit();
	int GetScore();
	int GetNumOfShot();
	int GetNumOfHit();
	float GetAccuracy();
	void Reset();
}
