#pragma once
#include "../../Engine/GameObject.h"
#include "../../Engine/SphereCollider.h"
#include "../../Engine/Camera.h"

class Bullet : public GameObject
{
private:
	XMFLOAT3 move_;
	SphereCollider* collision;

	const float BULLET_SPEED = 5;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void Shot(XMVECTOR direction);
};