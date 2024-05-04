#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"
#include "../../Engine/Image.h"
#include "../../GlobalValiable.h"

class PlayUI : public GameObject
{
private:
	//Text* time_;
	Text* score_;
	int BaseImage_;


public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayUI(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};