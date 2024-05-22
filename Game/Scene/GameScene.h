#pragma once
#include "../../Engine/GameObject.h"

class GameScene : public GameObject
{
	XMFLOAT3 enemyPos[4];

public:
	//�R���X�g���N�^
//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

