#include "Option.h"

Option::Option(GameObject* parent)
{
}

void Option::Initialize()
{
	optionImage_ = Image::Load("UI/Option.png");
	assert(optionImage_ >= 0);

	Instantiate<Button>(this);
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
