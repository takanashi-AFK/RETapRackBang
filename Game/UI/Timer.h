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

	//�^�C�}�[�̊J�n
	void Start();

	//�^�C�}�[�̒�~
	void Stop();

	/// <summary>
	/// �^�C�}�[���I���������ǂ���
	/// </summary>
	/// <returns>�^�C�}�[���I�� = true</returns>
	bool GetTimerEnd();

	/// <summary>
	/// ���b�Ԃ̃^�C�}�[����ݒ�
	/// </summary>
	/// <param name="_time">���b�J�E���g���邩(�b)</param>
	void SetTime(int _time);


};