#pragma once
namespace ScoreManager
{
	/// <summary>
	/// �ˌ���+1
	/// </summary>
	void AddNumOfShot();

	/// <summary>
	/// ������+1
	/// </summary>
	void AddNumOfHit();

	/// <summary>
	/// �X�R�A���擾
	/// </summary>
	/// <returns>accuracy�Ǝˌ��񐔂���v�Z�����X�R�A</returns>
	int GetScore();

	/// <summary>
	/// �ˌ��񐔂��擾
	/// </summary>
	int GetNumOfShot();

	/// <summary>
	/// �����񐔂��擾
	/// </summary>
	int GetNumOfHit();

	/// <summary>
	/// ���������擾
	/// </summary>
	float GetAccuracy();

	/// <summary>
	/// �e�ϐ������Z�b�g
	/// </summary>
	void Reset();
}
