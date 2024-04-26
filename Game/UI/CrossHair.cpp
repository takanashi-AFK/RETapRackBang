#include "CrossHair.h"

CrossHair::CrossHair(GameObject* parent):
	GameObject(parent,"CrossHair"),
	crosshairImage_{}
{
}

void CrossHair::Initialize()
{
	crosshairImage_ = Image::Load("crossHair.png");
	assert(crosshairImage_ >= 0);
}

void CrossHair::Update()
{
}

void CrossHair::Draw()
{
	Image::SetTransform(crosshairImage_, transform_);
	Image::Draw(crosshairImage_);
}

void CrossHair::Release()
{
}
