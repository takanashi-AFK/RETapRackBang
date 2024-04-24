#pragma once
#include"../../Engine/GameObject.h"
#include"../../Engine/SphereCollider.h"
class SphereTarget:public GameObject
{
private:
	int targetModelHandle_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SphereTarget(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�Փ˂�����
	void OnCollision(GameObject* pTarget)override;
};

