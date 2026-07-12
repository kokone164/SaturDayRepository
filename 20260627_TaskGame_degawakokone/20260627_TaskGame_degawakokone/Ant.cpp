#include"Ant.h"

//コンストラクタ
Ant::Ant()
{
	x = 0;
	y = 0;
	speed = 300.0f;
	timer = 0.0f;
	state = &g_HiddenState;
}

//===================================
//更新
//===================================
void Ant::Update(float dt)
{
	state->Update(*this, dt);
}
//===================================
//描画
//===================================
void Ant::Draw(int normalImage, int hitImage)
{
	state->Draw(*this, normalImage, hitImage);
}
//===================================
//ヒット
//===================================
bool Ant::IsHit(int mx, int my)
{
	return state->OnClick(*this, mx, my);
}
//===================================
//状態変化
//===================================
void Ant::ChangeState(IAntState* newState)
{
	timer = 0.0f;
	state = newState;
}