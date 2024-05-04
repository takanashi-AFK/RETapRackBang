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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CountDown(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	STATE GetCurrentState();
};