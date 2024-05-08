#pragma once
#include "../../Engine/GameObject.h"
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

	/// <summary>
	/// �ˌ��\���ǂ�����ݒ�
	/// </summary>
	/// <param name="_canShot">�ˌ��\ = true</param>
	void SetCanShot(bool _canShot);

	/// <summary>
	/// �ˌ��G�t�F�N�g�̐ݒ�
	/// </summary>
	void ShotEffect();

};