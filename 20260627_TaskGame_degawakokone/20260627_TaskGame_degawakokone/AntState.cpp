#include"AntState.h"
#include"Ant.h"
#include"DxLib.h"

//共有インスタンス
HiddenState g_HiddenState;
VisibleState g_VisibleState;
HitState g_HitState;

//===================================
//Hidden(非表示)
//===================================
//更新
void HiddenState::Update(Ant& ant, float dt)
{
	//時間経過
	ant.timer += dt;
	//1秒経過したら
	if (ant.timer >= 0.5f + GetRand(5) * 0.5f)
	{
		ant.x = 0;
		ant.y = GetRand(500 - 10) + 10;
		//状態を表示に切り替える
		ant.ChangeState(&g_VisibleState);
	}
}
//描画
void HiddenState::Draw(Ant& ant, int, int){}
//クリック
bool HiddenState::OnClick(Ant&, int, int) { return false; }

//===================================
//Visible(表示)
//===================================
//更新
void VisibleState::Update(Ant& ant, float dt)
{
	ant.x += ant.speed * dt;

	ant.timer += dt;
	if (ant.x > 800 + 75)
	{
		ant.ChangeState(&g_HiddenState);
	}
}

//描画
void VisibleState::Draw(Ant& ant, int normalImage, int)
{
	DrawExtendGraph((int)ant.x, (int)ant.y,
			(int)ant.x + 75, (int)ant.y + 75,
			normalImage, TRUE);
}
//クリック
bool VisibleState::OnClick(Ant& ant, int mx, int my)
{
	//当たり判定
	if (mx >= ant.x && mx <= ant.x + 75 &&
		my >= ant.y && my <= ant.y + 75)
	{
		ant.ChangeState(&g_HitState);
		return true;
	}

	return false;
}

//===================================
//Hit(叩かれた)
//===================================
//更新
void HitState::Update(Ant& ant, float dt)
{
	ant.timer += dt;
	if (ant.timer >= 0.5f)
	{
		ant.ChangeState(&g_HiddenState);
	}
}
//描画
void HitState::Draw(Ant& ant, int, int hitImage)
{
	DrawExtendGraph((int)ant.x, (int)ant.y,
		(int)ant.x + 75, (int)ant.y + 75,
		hitImage, TRUE);
}
//クリック
bool HitState::OnClick(Ant& ant, int mx, int my) { return false; }
