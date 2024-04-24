#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/SphereCollider.h"
#include "../../Engine/Camera.h"

class Bullet : public GameObject
{
private:
	XMFLOAT3 move_;
	SphereCollider* collision;

	const float BULLET_SPEED = 5;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void Shot(XMVECTOR direction);
};