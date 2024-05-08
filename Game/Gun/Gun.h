#pragma once
#include "../../Engine/GameObject.h"
#include"../Manager/SoundManager.h"
#include "../../Engine/VFX.h"

class Gun : public GameObject
{
private:
	int gunModelHandle_;
	bool canShot_;
	EmitterData shotEffect_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Gun(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetCanShot(bool _canShot);

	void ShotEffect();

};