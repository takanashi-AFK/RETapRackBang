#include "SphereTarget.h"
#include "../../Engine/Model.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../TestScene.h"
SphereTarget::SphereTarget(GameObject* parent):
	GameObject(parent,"SphereTarget")
{
}

void SphereTarget::Initialize()
{
	targetModelHandle_ = Model::Load("targetB.fbx");
	assert(targetModelHandle_ >= 0);

	SphereCollider* spc = new SphereCollider(XMFLOAT3(0, 0, 0),1.f);
	AddCollider(spc);
}

void SphereTarget::Update()
{
	ImGui::Begin("Target");
	ImGui::DragFloat3("pos", &transform_.position_.x);
	ImGui::End();
}

void SphereTarget::Draw()
{
	Model::SetTransform(targetModelHandle_, transform_);
	Model::Draw(targetModelHandle_);
}

void SphereTarget::Release()
{
}



void SphereTarget::OnCollision(GameObject* pTarget)
{
	TestScene* testScene = (TestScene*)FindObject("TestScene");
	if (pTarget->GetObjectName() == "Bullet")
	{
		KillMe();
		pTarget->KillMe();
		XMFLOAT3 pos = transform_.position_;
		testScene->OnAction(pos);
	}
}

