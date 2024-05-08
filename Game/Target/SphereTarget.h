#pragma once
#include"../../Engine/GameObject.h"
#include"../../Engine/SphereCollider.h"
#include "../../Engine/VFX.h"

class SphereTarget:public GameObject
{
private:
	int targetModelHandle_;
	EmitterData bulletHit_;
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
	void OnAction()override;

	//���f���n���h���̎擾
	int GetModelHandle() {return targetModelHandle_; }

	//�e�������������̃G�t�F�N�g�̐ݒ�
	void InitBulletHitEff();
};

