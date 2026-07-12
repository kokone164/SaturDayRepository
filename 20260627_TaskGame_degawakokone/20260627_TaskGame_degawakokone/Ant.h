#pragma once
#include"AntState.h"

///========================================================
///アリ個体クラス
/// ・位置
/// ・状態
/// ・タイマー
/// ========================================================

class Ant
{
public:
	float x, y;//アリの座標
	float speed;//アリの移動速度
	float timer;//アリのタイマー
	IAntState* state;//アリの状態管理インターフェース

	//コンストラクタ
	Ant();

	void Update(float dt);
	void Draw(int normalImage, int hitImage);
	bool IsHit(int mx, int my);
	void ChangeState(IAntState* newState);

};
