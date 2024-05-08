#include "SoundManager.h"
#include<cassert>

namespace SoundManager
{
	int confirmSoundHandle_;
	int hitSoundHandle_;
	int shotSoundHandle_;

	void PlayConfirmSound()
	{
		confirmSoundHandle_ = Audio::Load("Sounds/Confirm.wav", false);
		assert(confirmSoundHandle_ >= 0);
		Audio::Play(confirmSoundHandle_);
	}

	void PlayHitSound()
	{
		hitSoundHandle_ = Audio::Load("Sounds/Jump.wav", false, 10);
		assert(hitSoundHandle_ >= 0);
		Audio::Play(hitSoundHandle_);
	}

	void PlayShotSound()
	{
		shotSoundHandle_ = Audio::Load("Sounds/Œe‚ðŒ‚‚Â.wav", false, 10);
		assert(shotSoundHandle_ >= 0);
		Audio::Play(shotSoundHandle_);
	}

	void StopConfirmSound()
	{
		Audio::Stop(confirmSoundHandle_);
	}

	void StopHitSound()
	{
		Audio::Stop(hitSoundHandle_);
	}

	void StopShotSound()
	{
		Audio::Stop(shotSoundHandle_);
	}

}
