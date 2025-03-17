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

	transform_.scale_ = { 0.5,0.5,0 };
	transform_.position_.x = 0.1f;
	transform_.position_.y = -0.45f;
	pTimer_ = (Timer*)FindObject("Timer");
	pTimer_->Stop();
}

void Button::Update()
{
	mousePos_ = Input::GetMousePosition();

	isPushable = IsMouseInRect(mousePos_);
	if (isPushable && Input::IsMouseButtonDown(0)) {
		SoundManager::PlayConfirmSound();
		PostQuitMessage(0);
	}

	/*ImGui::DragFloat2("Button Position", &transform_.position_.x, 0.01f,-1,1);
	ImGui::DragFloat2("Button scale", &transform_.scale_.x, 0.01f,-1,1);*/
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
	
	size = Image::GetSize(selectButton_);
	center_ = XMFLOAT3(size.x,size.y, 0);
}

void Button::Release()
{
	pTimer_->Start();
}

bool Button::IsMouseInRect(XMFLOAT3 mousePos)
{
	if (abs(mousePos.x - center_.x) > size.x / 2)
		return false;
	if (abs(mousePos.y - center_.y) > size.y / 2)
		return false;
	return true;
}

void Button::SetPosition(float x, float y)
{
	transform_.position_.x = (x - Direct3D::screenWidth_ / 2) / Direct3D::screenWidth_;
	transform_.position_.y = -(y - Direct3D::screenHeight_ / 2) / (Direct3D::screenHeight_ / 2);

}
