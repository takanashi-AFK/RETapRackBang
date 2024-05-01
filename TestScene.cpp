#include "TestScene.h"
#include "Game/Stage/SimpleStage.h"
#include "Game/Player/Player.h"
#include "Game/UI/CrossHair.h"
#include "Game/Stage/SkySphere.h"
#include "Game/Target/TargetManager.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
	Instantiate<TargetManager>(this);
	Instantiate<CrossHair>(this);
}

//�X�V
void TestScene::Update()
{
	SetCursorPos(screenWidth/2,screenHeight/2);
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}


