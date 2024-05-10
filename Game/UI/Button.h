#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/Input.h"
#include "../../Engine/Image.h"
#include "../Manager/SoundManager.h"
class Button :public GameObject
{
private:
	int normalButton_;
	int selectButton_;
	XMFLOAT3 mousePos_;
	bool isPushable;
public:
	Button(GameObject* parent);

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	bool IsMouseInRect();
};

