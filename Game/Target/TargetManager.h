#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/Direct3D.h"
#include "SphereTarget.h"
#include <array>
//�e�X�g�V�[�����Ǘ�����N���X

const int PLACE_SIZE{ 4 };
const int TARGET_NUM{ 3 };
const float PLACE_OUTSET{ 3.f };
const float PLACE_HEIGHT_OUTSET{ 5 };
const float PLACE_DEPTH{ 35 };

class TargetManager : public GameObject
{
private:
	std::array<SphereTarget*, TARGET_NUM> pSp;
	XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
	XMFLOAT3 brokenTargetPos_;
	int xPos_, yPos_;
	std::array<XMFLOAT3, TARGET_NUM> previousPos_;

	int brokenTarget_;
	bool isTargetBroken_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TargetManager(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// �^�[�Q�b�g���e�ɓ���������Ă΂��֐�
	/// </summary>
	/// <param name="pos">�j�󂳂ꂽ�^�[�Q�b�g�̈ʒu</param>
	void OnAction(XMFLOAT3 pos)override;

	/// <summary>
	/// �^�[�Q�b�g�̏�������
	/// </summary>
	void GenerateTarget();

	/// <summary>
	/// �^�[�Q�b�g�̍Đ���
	/// </summary>
	void ReGenerateTarget();

	std::array<SphereTarget*, 3> GetSphereTarget() { return pSp; }

};
