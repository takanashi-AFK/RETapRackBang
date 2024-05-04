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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Timer(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void Start();

	void Stop();

	bool GetTimerEnd();

	void SetTime(int _time);


};