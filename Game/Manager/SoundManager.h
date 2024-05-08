#pragma once
#include "../../Engine/Audio.h"
namespace SoundManager
{
	/// <summary>
	/// ���艹���Đ�
	/// </summary>
	void PlayConfirmSound();

	/// <summary>
	/// ���������Đ�
	/// </summary>
	void PlayHitSound();

	/// <summary>
	/// �ˌ������Đ�
	/// </summary>
	void PlayShotSound();

	void StopConfirmSound();
	void StopHitSound();
	void StopShotSound();
};

