#include "Gun.h"
#include "../Target/SphereTarget.h"
#include "../../Engine/Model.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/ImGui/imgui.h"
#include "../Player/Player.h"
#include "../Target/TargetManager.h"
#include "../../GlobalValiable.h"
Gun::Gun(GameObject* parent) :
	GameObject(parent, "Gun"),
	gunModelHandle_(-1),
	canShot_(true)
{
}

void Gun::Initialize()
{
	gunModelHandle_ = Model::Load("Player/blasterM.fbx");
	assert(gunModelHandle_ >= 0);
	ShotEffect();
}

void Gun::Update()
{
	shotEffect_.position = { transform_.position_.x + 2, transform_.position_.y + 2, transform_.position_.z };

	if (Input::IsMouseButtonDown(0) && canShot_) {
		SoundManager::PlayShotSound();
		ShotEffect();
		VFX::Start(shotEffect_);
		
		XMVECTOR sightLine = Camera::GetSightLine();
		XMFLOAT3 campos = Camera::GetPosition();

		SphereTarget* spt = (SphereTarget*)FindObject("SphereTarget");
		TargetManager* tm = (TargetManager*)FindObject("TargetManager");
		std::array<SphereTarget*, 3> targetList = tm->GetSphereTarget();

		Player* pp = (Player*)FindObject("Player");

		XMFLOAT3 pPos;
		RayCastData bullet;
		
		if (spt != nullptr) {
			for (auto target : targetList) {
				XMStoreFloat3(&pPos, XMVector3Normalize(pp->GetPlayerVector()));
				bullet.start = campos;
				XMStoreFloat3(&bullet.dir, sightLine);
				Model::RayCast(target->GetModelHandle(), &bullet);
				if (bullet.hit)
				{
					target->IsHit();
				}
			}
		}
		
	}
}

void Gun::Draw()
{
	Model::SetTransform(gunModelHandle_, transform_);
	Model::Draw(gunModelHandle_);
}

void Gun::Release()
{
}

void Gun::SetCanShot(bool _canShot)
{
	canShot_ = _canShot;
}

void Gun::ShotEffect()
{
	shotEffect_.delay = 0;
	shotEffect_.number = 1;
	shotEffect_.lifeTime = 3;
	shotEffect_.size = XMFLOAT2(5,5);
	shotEffect_.color = XMFLOAT4(1, 1, 0.1, 0.5);
}
