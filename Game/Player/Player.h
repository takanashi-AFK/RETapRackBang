#pragma once
#include "../../Engine/GameObject.h"
class Gun;
//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
private:
	XMVECTOR playerVec_;
	int pModelHandle_;
	bool canMove_;
	Gun* pGun;

	//�J�����֘A
	const float sensitivity = 0.05f;
	XMFLOAT3 rotateAngle_;
	XMFLOAT3 newCenter_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// �v���C���[�̈ړ�
	/// </summary>
	void PlayerMove();

	/// <summary>
	/// TPS�J����
	/// </summary>
	void TPSCam();

	/// <summary>
	/// �v���C���[���ړ��\���ǂ�����ݒ�
	/// </summary>
	/// <param name="_canMove">�ړ��\ = true</param>
	void SetCanMove(bool _canMove);

	/// <summary>
	/// �v���C���[�̌����Ă���������擾
	/// </summary>
	/// <returns>�v���C���[�̐���</returns>
	XMVECTOR GetPlayerVector() { return playerVec_; }
};