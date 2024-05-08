#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/Input.h"
#include "../../Engine/Text.h"
#include "../../GlobalValiable.h"
#include "../Manager/SoundManager.h"

class ResultScene : public GameObject
{
private:
	int resultImageHandle_;
	Text* score_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	ResultScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};