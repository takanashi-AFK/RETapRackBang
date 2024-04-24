#include "Gun.h"
#include "Bullet.h"
#include "../../Engine/Model.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"

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
	XMVECTOR sightLine = Camera::GetSightLine();

	if (Input::IsMouseButtonDown(0)) {
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(-sightLine);
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
