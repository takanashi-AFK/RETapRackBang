#include "TargetManager.h"

TargetManager::TargetManager(GameObject* parent):
	GameObject(parent, "TargetManager"),
	brokenTargetPos_{},
	brokenTarget_{},
	isTargetBroken_(false),
	pSp{}, previousPos_{},
	targetPlace_{},
	xPos_{}, yPos_{}
{
}

void TargetManager::Initialize()
{
	GenerateTarget();
}

void TargetManager::Update()
{
	if (isTargetBroken_) {
		ReGenerateTarget();
	}
}

void TargetManager::Draw()
{
}

void TargetManager::Release()
{
}

void TargetManager::OnAction(XMFLOAT3 pos)
{
	brokenTargetPos_ = pos;
	isTargetBroken_ = true;
}

void TargetManager::GenerateTarget()
{
	for (int y = 0; y < PLACE_SIZE; y++)
		for (int x = 0; x < PLACE_SIZE; x++) {
			targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y + PLACE_HEIGHT_OUTSET, PLACE_DEPTH);
		}

	pSp[0] = Instantiate<SphereTarget>(this);
	xPos_ = rand() % PLACE_SIZE;
	yPos_ = rand() % PLACE_SIZE;

	pSp[0]->SetPosition(targetPlace_[xPos_][yPos_]);
	previousPos_[0] = targetPlace_[xPos_][yPos_];

	//Ç‡Çµ1Ç∆èdÇ»Ç¡ÇƒÇΩÇÁ
	do {
		xPos_ = rand() % PLACE_SIZE;
		yPos_ = rand() % PLACE_SIZE;
	} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[0].y == targetPlace_[xPos_][yPos_].y);
	pSp[1] = Instantiate<SphereTarget>(this);
	pSp[1]->SetPosition(targetPlace_[xPos_][yPos_]);
	previousPos_[1] = targetPlace_[xPos_][yPos_];


	//Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
	do {
		xPos_ = rand() % PLACE_SIZE;
		yPos_ = rand() % PLACE_SIZE;
	} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[0].y == targetPlace_[xPos_][yPos_].y ||
		previousPos_[1].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[1].y == targetPlace_[xPos_][yPos_].y);

	pSp[2] = Instantiate<SphereTarget>(this);
	pSp[2]->SetPosition(targetPlace_[xPos_][yPos_]);
	previousPos_[2] = targetPlace_[xPos_][yPos_];
}

void TargetManager::ReGenerateTarget()
{
	
	for (int i = 0; i < 3; i++)
		if (brokenTargetPos_.x == previousPos_[i].x && brokenTargetPos_.y == previousPos_[i].y)
			brokenTarget_ = i;

	//Ç‡ÇµÇPÇ∆ÅAÇQÇ∆èdÇ»Ç¡ÇƒÇΩÇÁ
	do {
		xPos_ = rand() % PLACE_SIZE;
		yPos_ = rand() % PLACE_SIZE;
	} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[0].y == targetPlace_[xPos_][yPos_].y ||
		previousPos_[1].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[1].y == targetPlace_[xPos_][yPos_].y ||
		previousPos_[2].x == targetPlace_[xPos_][yPos_].x &&
		previousPos_[2].y == targetPlace_[xPos_][yPos_].y);

	pSp[brokenTarget_] = Instantiate<SphereTarget>(this);
	pSp[brokenTarget_]->SetPosition(targetPlace_[xPos_][yPos_]);
	previousPos_[brokenTarget_] = targetPlace_[xPos_][yPos_];

	isTargetBroken_ = false;
}
