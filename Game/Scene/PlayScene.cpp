#include "PlayScene.h"
#include "../../Game/Stage/SimpleStage.h"
#include "../../Game/Player/Player.h"
#include "../../Game/UI/CrossHair.h"
#include "../../Game/Stage/SkySphere.h"
#include "../../Game/Target/TargetManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
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
void PlayScene::Update()
{
	SetCursorPos(screenWidth/2,screenHeight/2);
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}


