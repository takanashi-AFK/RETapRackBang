#include "GameScene.h"
#include "../../Game/Stage/SimpleStage.h"
#include "../../Game/Stage/SkySphere.h"
#include "../../Game/Player/Player.h"
namespace {

	const float MAPSIZE{ 70 };
}

GameScene::GameScene(GameObject* parent)
{
}

void GameScene::Initialize()
{
	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);

	ShowCursor(false);
	enemyPos[0] = { MAPSIZE, 0, MAPSIZE };
	enemyPos[1] = { MAPSIZE, 0, -MAPSIZE };
	enemyPos[2] = { -MAPSIZE, 0, MAPSIZE };
	enemyPos[3] = { -MAPSIZE, 0, -MAPSIZE };
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
}

void GameScene::Release()
{
}
