#pragma once
#include "../../Engine/Audio.h"
namespace SoundManager
{
	/// <summary>
	/// 決定音を再生
	/// </summary>
	void PlayConfirmSound();

	/// <summary>
	/// 命中音を再生
	/// </summary>
	void PlayHitSound();

	/// <summary>
	/// 射撃音を再生
	/// </summary>
	void PlayShotSound();

	void StopConfirmSound();
	void StopHitSound();
	void StopShotSound();
};

