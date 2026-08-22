#pragma once
class Collision
{
public:
	/// <summary>
	/// 短形同士が衝突しているか調べる
	/// </summary>
	/// <param name="left1"></param>
	/// <param name="top1"></param>
	/// <param name="right1"></param>
	/// <param name="bottom1"></param>
	/// <param name="left2"></param>
	/// <param name="top2"></param>
	/// <param name="right2"></param>
	/// <param name="bottom2"></param>
	/// <returns></returns>
	static bool IsHitRect(float left1, float top1, float right1, float bottom1,
		float left2, float top2, float right2, float bottom2);
};