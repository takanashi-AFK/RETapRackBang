#pragma once
#include "../../Engine/GameObject.h"
#include "../../Game/Target/SphereTarget.h"
#include <array>
//�e�X�g�V�[�����Ǘ�����N���X
class Timer;
class Option;

class PlayScene : public GameObject
{
private:
	int screenWidth;		//�X�N���[���̕�
	int screenHeight;	//�X�N���[���̍���

	bool isOption_;
	Option* opt;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};