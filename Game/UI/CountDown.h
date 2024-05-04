#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Image.h"
class Player;
class Timer;
class CountDown : public GameObject
{
private:
	enum STATE {
		ONE= 1,
		TWO,
		THREE,
		START,
		END
	};
	STATE state;
	int countImage_[4];
	int frame;
	Timer* pTimer;

	Player* pPlayer;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CountDown(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	STATE GetCurrentState();
};