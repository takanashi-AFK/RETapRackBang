#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Engine/SceneManager.h"
#include "../../Engine/Transition.h"

class SplashScene : public GameObject
{
private:
	int splashImageHandle_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	SplashScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};