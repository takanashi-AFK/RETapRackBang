#include "Gun.h"
#include "Bullet.h"
#include "../Target/SphereTarget.h"
#include "../../Engine/Model.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/ImGui/imgui.h"
#include "../Player/Player.h"
#include "../../TestScene.h"

Gun::Gun(GameObject* parent) :
	GameObject(parent, "Gun")
{
}

void Gun::Initialize()
{
	GunModelHandle_ = Model::Load("Player/blasterM.fbx");
	assert(GunModelHandle_ >= 0);
}

void Gun::Update()
{
	if (Input::IsMouseButtonDown(0)) {
		XMVECTOR sightLine = Camera::GetSightLine();
		XMFLOAT3 campos = Camera::GetPosition();

		SphereTarget* spt = (SphereTarget*)FindObject("SphereTarget");
		TestScene* tss = (TestScene*)FindObject("TestScene");
		std::array<SphereTarget*, 3> targetList = tss->GetSphereTarget();

		Player* pp = (Player*)FindObject("Player");

		XMFLOAT3 pPos;
		RayCastData bullet;
		
		if (spt != nullptr) {
			for (auto target : targetList) {
				ImGui::Text("%d", target->GetModelHandle());
				XMStoreFloat3(&pPos, XMVector3Normalize(pp->GetPlayerVector()));
				//bullet.start = { pPos.x + campos.x,pPos.y + campos.y, pPos.z + campos.z };
				bullet.start = campos;
				XMStoreFloat3(&bullet.dir, sightLine);
				Model::RayCast(target->GetModelHandle(), &bullet);
				if (bullet.hit)
				{
					target->IsHit();
				}
			}
			
			//vectorを取得
			//そのリストすべてに対してレイを撃つ
			//当たったらそのターゲットを破壊
		}
		


	}

	
}

void Gun::Draw()
{
	Model::SetTransform(GunModelHandle_, transform_);
	Model::Draw(GunModelHandle_);
}

void Gun::Release()
{
}
