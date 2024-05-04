#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
#include "../../Engine/ImGui/imgui.h"
#include "../../Engine/Input.h"
#include "../../Engine/SceneManager.h"

class TitleScene : public GameObject
{
private:
	int titleImageHandle_;
	int pressSpaceImageHandle_;

	bool incleasing_;
	int opacity_;
	Transform spaceKeyTrans_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};