#pragma once
#include "../../Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class SimpleStage : public GameObject
{
private:
	int stageModelHandle_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SimpleStage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//���f���n���h���̎擾
	int GetModelHandle() { return stageModelHandle_; }
};