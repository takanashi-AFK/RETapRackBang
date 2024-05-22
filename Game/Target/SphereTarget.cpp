#include "SphereTarget.h"
#include "../../Engine/Model.h"
#include "../../Engine/ImGui/imgui.h"
#include "TargetManager.h"
#include "../../GlobalValiable.h"
#include "../Manager/ScoreManager.h"

SphereTarget::SphereTarget(GameObject* parent):
	GameObject(parent,"SphereTarget"),
	targetModelHandle_(-1)
{
}

void SphereTarget::Initialize()
{
	targetModelHandle_ = Model::Load("targetB.fbx");
	assert(targetModelHandle_ >= 0);
	InitBulletHitEff();
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
	bulletHit_.position = XMFLOAT3(transform_.position_);
}

void SphereTarget::OnAction()
{
	TargetManager* tm = (TargetManager*)FindObject("TargetManager");

	KillMe();
	XMFLOAT3 pos = transform_.position_;
	bulletHit_.position = pos;
	VFX::Start(bulletHit_);

	tm->OnAction(pos);
	ScoreManager::AddScore();
}

void SphereTarget::InitBulletHitEff()
{
	bulletHit_.delay = 0;
	bulletHit_.number = 20;
	bulletHit_.lifeTime = 20;
	bulletHit_.positionRnd = XMFLOAT3(0.05, 0, 0.05);
	bulletHit_.direction = XMFLOAT3(0, 1, 0);
	bulletHit_.directionRnd = XMFLOAT3(90, 90, 90);
	bulletHit_.speed = 0.25f;
	bulletHit_.speedRnd = 1;
	bulletHit_.accel = 0.93;
	bulletHit_.size = XMFLOAT2(0.25,0.25);
	bulletHit_.sizeRnd = XMFLOAT2(0.2, 0.2);
	bulletHit_.scale = XMFLOAT2(0.99, 0.99);
	bulletHit_.color = XMFLOAT4(1, 1, 0.1, 1);
	bulletHit_.deltaColor = XMFLOAT4(0, 0, 0, 0);
}

