#include "TargetManager.h"


TargetManager::TargetManager(GameObject* parent):
	GameObject(parent, "TargetManager"),
	brokenTargetPos_{},
	brokenTarget_{},
	isTargetBroken_(false),
	pSp{}, previousPos_{},
	targetPlace_{},
	xPos_{}, yPos_{},
	overlapping_(false)
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
	//ターゲットの位置を決める
	for (int y = 0; y < PLACE_SIZE; y++)
		for (int x = 0; x < PLACE_SIZE; x++) {
			targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y + PLACE_HEIGHT_OUTSET, PLACE_DEPTH);
		}

	for (int i = 0; i < TARGET_NUM; i++) {

		do {//ここ関数化したい
			overlapping_ = false;
			xPos_ = rand() % PLACE_SIZE;
			yPos_ = rand() % PLACE_SIZE;

			//previousPos_内のすべての要素との重なりをチェック
			for (const auto& pos : previousPos_) {
				if (pos.x == targetPlace_[xPos_][yPos_].x && pos.y == targetPlace_[xPos_][yPos_].y) {
					overlapping_ = true;
					break;
				}
			}
		} while (overlapping_);

		pSp[i] = Instantiate<SphereTarget>(this);
		pSp[i]->SetPosition(targetPlace_[xPos_][yPos_]);
		previousPos_[i] = targetPlace_[xPos_][yPos_];
	}

}

void TargetManager::ReGenerateTarget()
{
	
	for (int i = 0; i < TARGET_NUM; i++)
		if (brokenTargetPos_.x == previousPos_[i].x && brokenTargetPos_.y == previousPos_[i].y) {
			brokenTarget_ = i;
			break;
		}

		do {
			xPos_ = rand() % PLACE_SIZE;
			yPos_ = rand() % PLACE_SIZE;
			overlapping_ = false;
			//previousPos_内のすべての要素との重なりをチェック
			for (const auto& pos : previousPos_) {
				if (pos.x == targetPlace_[xPos_][yPos_].x && pos.y == targetPlace_[xPos_][yPos_].y) {
					overlapping_ = true;
					break;
				}
			}
		} while (overlapping_);


		pSp[brokenTarget_] = Instantiate<SphereTarget>(this);
		pSp[brokenTarget_]->SetPosition(targetPlace_[xPos_][yPos_]);
		previousPos_[brokenTarget_] = targetPlace_[xPos_][yPos_];

		isTargetBroken_ = false;
}
