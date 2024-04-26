#include "SkySphere.h"

SkySphere::SkySphere(GameObject* parent)
{
}

void SkySphere::Initialize()
{
	hSkySphere = Model::Load("Stage/SkySphere.fbx");
	assert(hSkySphere >= 0);

}

void SkySphere::Update()
{
#ifdef _DEBUG
	ImGui::Begin("rueausu");

	
		ImGui::DragFloat3("pos", &transform_.position_.x);
		if (ImGui::Button("ResetPos")) {
			transform_.position_.x = 0;
			transform_.position_.y = -30;
			transform_.position_.z = 0;
		}
	

	ImGui::End();
#endif // _DEBUG
}

void SkySphere::Draw()
{
	Model::SetTransform(hSkySphere, transform_);
	Model::Draw(hSkySphere);
}

void SkySphere::Release()
{
}
