#include "Gun.h"
//エンジンinclude
#include "../../Engine/Model.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/ImGui/imgui.h"

//自作クラスinclude
#include "../Player/Player.h"
#include "../Target/TargetManager.h"
#include "../Target/SphereTarget.h"
#include "../../GlobalValiable.h"
#include"../Manager/SoundManager.h"

Gun::Gun(GameObject* parent) :
	GameObject(parent, "Gun"),
	gunModelHandle_(-1),
	canShot_(true)
{
}

void Gun::Initialize()
{
	//銃のモデルを読み込む
	gunModelHandle_ = Model::Load("Player/blasterM.fbx");
	assert(gunModelHandle_ >= 0);
}

void Gun::Update()
{
	//もしマウスの左ボタンが押されたら
	if (Input::IsMouseButtonDown(0) && canShot_) {

		g_NumOfHit++;
		//射撃音を再生
		SoundManager::PlayShotSound();

		//FIXME: エフェクトを再生(現時点だと位置のずれが発生)
		shotEffect_.position = { transform_.position_.x + 2, transform_.position_.y + 2, transform_.position_.z };
		ShotEffect();
		VFX::Start(shotEffect_);
		
		//視線ベクトルを取得
		XMVECTOR sightLine = Camera::GetSightLine();
		//カメラの位置を取得
		XMFLOAT3 campos = Camera::GetPosition();

		//インスタンス用意
		SphereTarget* spt = (SphereTarget*)FindObject("SphereTarget");
		TargetManager* tm = (TargetManager*)FindObject("TargetManager");
		Player* pp = (Player*)FindObject("Player");

		std::array<SphereTarget*, TARGET_NUM> targetList = tm->GetSphereTarget();


		XMFLOAT3 pPos;
		RayCastData bullet;
		
		//ターゲットが存在していたら
		if (spt != nullptr) {
			//ターゲットに向けてレイキャスト
			for (auto target : targetList) {
				XMStoreFloat3(&pPos, XMVector3Normalize(pp->GetPlayerVector()));

				//弾の始点をカメラの位置に設定
				bullet.start = campos;

				//弾の方向を視線ベクトルに設定
				XMStoreFloat3(&bullet.dir, sightLine);

				//ターゲットのモデル向けてレイキャストを発射
				Model::RayCast(target->GetModelHandle(), &bullet);

				//もし当たったら
				if (bullet.hit){
					//ターゲットにヒットしたことを伝える
					target->OnAction();
				}
			}
		}
		
	}
}

void Gun::Draw()
{
	Model::SetTransform(gunModelHandle_, transform_);
	Model::Draw(gunModelHandle_);
}

void Gun::Release()
{
}

void Gun::SetCanShot(bool _canShot)
{
	canShot_ = _canShot;
}

void Gun::ShotEffect()
{
	shotEffect_.delay = 0;
	shotEffect_.number = 1;
	shotEffect_.lifeTime = 3;
	shotEffect_.size = XMFLOAT2(5,5);
	shotEffect_.color = XMFLOAT4(1, 1, 0.1, 0.5);
}
