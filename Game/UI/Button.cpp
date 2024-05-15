#include "Button.h"

#include "../Manager/SoundManager.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/ImGui/imgui.h"
#include "Timer.h"

Button::Button(GameObject* parent)
	: GameObject(parent, "Button"),
	normalButton_(-1),
	selectButton_(-1),
	isPushable(false)	
{
}

void Button::Initialize()
{
	normalButton_ = Image::Load("UI/Button/ExitNormal.png");
	assert(normalButton_ >= 0);
	selectButton_ = Image::Load("UI/Button/ExitSelect.png");
	assert(selectButton_ >= 0);
	pTimer_ = (Timer*)FindObject("Timer");
	pTimer_->Stop();
}

void Button::Update()
{
	mousePos_ = Input::GetMousePosition();

	isPushable = IsMouseInRect();
	if (isPushable && Input::IsMouseButtonDown(0)) {
		SoundManager::PlayConfirmSound();
		PostQuitMessage(0);
	}

	ImGui::DragFloat2("Button Position", &transform_.position_.x, 0.01f,-1,1);
	ImGui::DragFloat2("Button scale", &transform_.scale_.x, 0.01f,-1,1);
}

void Button::Draw()
{
	if (isPushable) {
		Image::SetTransform(selectButton_, transform_);
		Image::Draw(selectButton_);
	}
	else {
		Image::SetTransform(normalButton_, transform_);
		Image::Draw(normalButton_);
	}
}

void Button::Release()
{
	pTimer_->Start();
}

bool Button::IsMouseInRect()
{
	if (mousePos_.x > 1010 && mousePos_.x < 1320 && mousePos_.y > 670 && mousePos_.y < 830)
		return true;

	return false;
}
