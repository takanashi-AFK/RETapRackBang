#include "MenuScene.h"

MenuScene::MenuScene(GameObject* parent)
{
}

void MenuScene::Initialize()
{
	//画像データのロード
	menuImageHandle_ = Image::Load("Scene/MenuImage/Menu.png");
	assert(menuImageHandle_ >= 0);

}

void MenuScene::Update()
{
}

void MenuScene::Draw()
{
	Image::SetTransform(menuImageHandle_, transform_);
	Image::Draw(menuImageHandle_);
}

void MenuScene::Release()
{
}
