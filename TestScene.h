#pragma once
#include "Engine/GameObject.h"
#include "Game/Target/SphereTarget.h"
#include <array>
//�e�X�g�V�[�����Ǘ�����N���X

const int PLACE_SIZE{ 4 };
const int TARGET_NUM{ 3 };
const float PLACE_OUTSET{ 3.f };
const float PLACE_HEIGHT_OUTSET{ 5 };
const float PLACE_DEPTH{ 35 };

class TestScene : public GameObject
{
private:
	std::array<SphereTarget*,3> pSp;
	XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
	XMFLOAT3 brokenTargetPos_;

	std::array<XMFLOAT3, 3> previousPos_;

	int xPos_, yPos_;
	int brokenTarget_;
	bool isTargetBroken_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TestScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnAction(XMFLOAT3 pos)override;

	void GenerateSphereTarget();

	void ReGenerateSphereTarget();

	std::array<SphereTarget*, 3> GetSphereTarget() { return pSp; }
};