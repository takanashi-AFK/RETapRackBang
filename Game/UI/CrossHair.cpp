#include "CrossHair.h"


CrossHair::CrossHair(GameObject* parent):
	GameObject(parent,"CrossHair"),
	crosshairImage_{}
{
}

void CrossHair::Initialize()
{
	crosshairImage_ = Image::Load("2-2024-3-24.png");
	assert(crosshairImage_ >= 0);
}

void CrossHair::Update()
{
	Direct3D::SetDepthBafferWriteEnable(false);


}

void CrossHair::Draw()
{

	Image::SetTransform(crosshairImage_, transform_);
	Image::Draw(crosshairImage_);
}

void CrossHair::Release()
{
}
