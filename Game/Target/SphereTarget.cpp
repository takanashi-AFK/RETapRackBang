#include "SphereTarget.h"
#include "../../Engine/Model.h"
#include "../../Engine/ImGui/imgui.h"
#include "TargetManager.h"
SphereTarget::SphereTarget(GameObject* parent):
	GameObject(parent,"SphereTarget"),
	targetModelHandle_(-1)
{
}

void SphereTarget::Initialize()
{
	targetModelHandle_ = Model::Load("targetB.fbx");
	assert(targetModelHandle_ >= 0);
}

void SphereTarget::Update()
{
}

void SphereTarget::Draw()
{
	Model::SetTransform(targetModelHandle_, transform_);
	Model::Draw(targetModelHandle_);
}

void SphereTarget::Release()
{
}

void SphereTarget::IsHit()
{
	TargetManager* tm = (TargetManager*)FindObject("TargetManager");

	KillMe();
	XMFLOAT3 pos = transform_.position_;
	tm->OnAction(pos);
}

