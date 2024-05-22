#include "Gun.h"
//�G���W��include
#include "../../Engine/Model.h"
#include "../../Engine/Camera.h"
#include "../../Engine/Input.h"
#include "../../Engine/ImGui/imgui.h"

//����N���Xinclude
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
	//�e�̃��f����ǂݍ���
	gunModelHandle_ = Model::Load("Player/blasterM.fbx");
	assert(gunModelHandle_ >= 0);
}

void Gun::Update()
{
	//�����}�E�X�̍��{�^���������ꂽ��
	if (Input::IsMouseButtonDown(0) && canShot_) {

		g_NumOfHit++;
		//�ˌ������Đ�
		SoundManager::PlayShotSound();

		//FIXME: �G�t�F�N�g���Đ�(�����_���ƈʒu�̂��ꂪ����)
		shotEffect_.position = { transform_.position_.x + 2, transform_.position_.y + 2, transform_.position_.z };
		ShotEffect();
		VFX::Start(shotEffect_);
		
		//�����x�N�g�����擾
		XMVECTOR sightLine = Camera::GetSightLine();
		//�J�����̈ʒu���擾
		XMFLOAT3 campos = Camera::GetPosition();

		//�C���X�^���X�p��
		SphereTarget* spt = (SphereTarget*)FindObject("SphereTarget");
		TargetManager* tm = (TargetManager*)FindObject("TargetManager");
		Player* pp = (Player*)FindObject("Player");

		std::array<SphereTarget*, TARGET_NUM> targetList = tm->GetSphereTarget();


		XMFLOAT3 pPos;
		RayCastData bullet;
		
		//�^�[�Q�b�g�����݂��Ă�����
		if (spt != nullptr) {
			//�^�[�Q�b�g�Ɍ����ă��C�L���X�g
			for (auto target : targetList) {
				XMStoreFloat3(&pPos, XMVector3Normalize(pp->GetPlayerVector()));

				//�e�̎n�_���J�����̈ʒu�ɐݒ�
				bullet.start = campos;

				//�e�̕����������x�N�g���ɐݒ�
				XMStoreFloat3(&bullet.dir, sightLine);

				//�^�[�Q�b�g�̃��f�������ă��C�L���X�g�𔭎�
				Model::RayCast(target->GetModelHandle(), &bullet);

				//��������������
				if (bullet.hit){
					//�^�[�Q�b�g�Ƀq�b�g�������Ƃ�`����
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
