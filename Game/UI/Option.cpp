#include "Option.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Game/Player/Player.h"
Option::Option(GameObject* parent)
{
}

void Option::Initialize()
{
	optionImage_ = Image::Load("UI/Option.png");
	assert(optionImage_ >= 0);

	//Instantiate<Button>(this);
}

void Option::Update()
{
	ImGui::Begin("Option");
	Player* pp = (Player*)FindObject("Player");
	ImGui::DragFloat("sens", &pp->sensitivity, 0.1f, 0, 10);
	if(ImGui::Button("Exit")) PostQuitMessage(0);
	ImGui::End();
}

void Option::Draw()
{
	Image::SetTransform(optionImage_, transform_);
	Image::Draw(optionImage_);
}

void Option::Release()
{
}
