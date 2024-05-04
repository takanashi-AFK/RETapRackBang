#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Text.h"
#include "../../Engine/Image.h"

class Timer : public GameObject
{
private:
	int countTime_;
	int currentTime_;

	bool isCount_;
	bool isTimerEnd_;

	Text* time_;
	int BaseImage_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Timer(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void Start();

	void Stop();

	bool GetTimerEnd();

	void SetTime(int _time);


};