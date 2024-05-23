#pragma once
namespace ScoreManager
{
	/// <summary>
	/// 射撃回数+1
	/// </summary>
	void AddNumOfShot();

	/// <summary>
	/// 命中回数+1
	/// </summary>
	void AddNumOfHit();

	/// <summary>
	/// スコアを取得
	/// </summary>
	/// <returns>accuracyと射撃回数から計算したスコア</returns>
	int GetScore();

	/// <summary>
	/// 射撃回数を取得
	/// </summary>
	int GetNumOfShot();

	/// <summary>
	/// 命中回数を取得
	/// </summary>
	int GetNumOfHit();

	/// <summary>
	/// 命中率を取得
	/// </summary>
	float GetAccuracy();

	/// <summary>
	/// 各変数をリセット
	/// </summary>
	void Reset();
}
