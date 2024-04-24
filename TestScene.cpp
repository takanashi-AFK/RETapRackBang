#include "TestScene.h"
#include "Game/Stage/SimpleStage.h"
#include "Game/Player/Player.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	GenerateSphereTarget();
}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}

void TestScene::GenerateSphereTarget()
{
	//for (int y = 0; y < PLACE_SIZE; y++)
	//	for (int x = 0; x < PLACE_SIZE; x++) {
	//		targetPlace_[x][y] = XMFLOAT3(PLACE_OUTSET * x, PLACE_OUTSET * y + PLACE_HEIGHT_OUTSET, PLACE_DEPTH);
	//	}

	//pSp[0] = Instantiate<SphereTarget>(this);
	//xPos_ = rand() % PLACE_SIZE;
	//yPos_ = rand() % PLACE_SIZE;

	//pSp[0]->SetPosition(targetPlace_[xPos_][yPos_]);
	//previousPos_[0] = targetPlace_[xPos_][yPos_];

	////����1�Əd�Ȃ��Ă���
	//do {
	//	xPos_ = rand() % PLACE_SIZE;
	//	yPos_ = rand() % PLACE_SIZE;
	//} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x && previousPos_[0].y == targetPlace_[xPos_][yPos_].y);
	//pSp[1] = Instantiate<SphereTarget>(this);
	//pSp[1]->SetPosition(targetPlace_[xPos_][yPos_]);
	//previousPos_[1] = targetPlace_[xPos_][yPos_];


	////�����P�ƁA�Q�Əd�Ȃ��Ă���
	//do {
	//	xPos_ = rand() % PLACE_SIZE;
	//	yPos_ = rand() % PLACE_SIZE;
	//} while (previousPos_[0].x == targetPlace_[xPos_][yPos_].x &&
	//	previousPos_[0].y == targetPlace_[xPos_][yPos_].y ||
	//	previousPos_[1].x == targetPlace_[xPos_][yPos_].x &&
	//	previousPos_[1].y == targetPlace_[xPos_][yPos_].y);

	//pSp[2] = Instantiate<SphereTarget>(this);
	//pSp[2]->SetPosition(targetPlace_[xPos_][yPos_]);
	//previousPos_[2] = targetPlace_[xPos_][yPos_];

	for (int x = 0; x < TARGET_NUM; x++) {
		for (int y = 0; y < TARGET_NUM; y++) {
			pSp[x] = Instantiate<SphereTarget>(this);
			pSp[x]->SetPosition(x * PLACE_OUTSET, y * PLACE_OUTSET, PLACE_DEPTH);
		}
	}

}

