#include "Option.h"

Option::Option(GameObject* parent)
{
}

void Option::Initialize()
{
	optionImage_ = Image::Load("Scene/MenuImage/Scenario1ButtonSelected.png");
	assert(optionImage_ >= 0);
}

void Option::Update()
{
}

void Option::Draw()
{
	Image::SetTransform(optionImage_, transform_);
	Image::Draw(optionImage_);
}

void Option::Release()
{
}
