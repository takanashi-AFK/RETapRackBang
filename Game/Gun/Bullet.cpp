#include "Bullet.h"
#include "../../Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet")
{
}

void Bullet::Initialize()
{
	collision = new SphereCollider(transform_.position_, 0.05f);
	AddCollider(collision);
	camPos_ = Camera::GetPosition();
}

void Bullet::Update()
{
	transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;

	
}

void Bullet::Draw()
{
}

void Bullet::Release()
{
}

void Bullet::Shot(XMVECTOR direction)
{
	transform_.position_ = camPos_;
	XMVECTOR shotVec = direction;
	XMStoreFloat3(&move_, XMVector3Normalize(-shotVec) * BULLET_SPEED);
}


