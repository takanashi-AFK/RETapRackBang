#include "TestScene.h"
#include "Game/Stage/SimpleStage.h"
#include "Game/Player/Player.h"
#include "Game/UI/CrossHair.h"
#include "Game/Stage/SkySphere.h"

//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"),
	brokenTargetPos_{},
	brokenTarget_{},
	isTargetBroken_(false), 
	pSp{},previousPos_{},
	targetPlace_{},
	xPos_{},yPos_{}
{
}

//初期化
void TestScene::Initialize()
{
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	GenerateSphereTarget();
	Instantiate<CrossHair>(this);
}

//更新
void TestScene::Update()
{
	SetCursorPos(screenWidth/2,screenHeight/2);
	ReGenerateSphereTarget();
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}

void TestScene::OnAction(XMFLOAT3 pos)
{
	brokenTargetPos_ = pos;
	isTargetBroken_ = true;
}

void TestScene::GenerateSphereTarget()
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

	//もし1と重なってたら
	do {
		xPos_ = rand() % PLACE_SIZE;
		yPos_ = rand() % PLACE_SIZE;
	} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x &&
			 previousPos_[0].y == targetPlace_[xPos_][yPos_].y);
	pSp[1] = Instantiate<SphereTarget>(this);
	pSp[1]->SetPosition(targetPlace_[xPos_][yPos_]);
	previousPos_[1] = targetPlace_[xPos_][yPos_];


	//もし１と、２と重なってたら
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

	//for (int x = 0; x < TARGET_NUM; x++) {
	//	for (int y = 0; y < TARGET_NUM; y++) {
	//		pSp[x] = Instantiate<SphereTarget>(this);
	//		pSp[x]->SetPosition(x * PLACE_OUTSET, y * PLACE_OUTSET, PLACE_DEPTH);
	//	}
	//}

}

void TestScene::ReGenerateSphereTarget()
{
	if (isTargetBroken_) {

		for (int i = 0; i < 3; i++)
			if (brokenTargetPos_.x == previousPos_[i].x && brokenTargetPos_.y == previousPos_[i].y)
				brokenTarget_ = i;

		//もし１と、２と重なってたら
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
}


