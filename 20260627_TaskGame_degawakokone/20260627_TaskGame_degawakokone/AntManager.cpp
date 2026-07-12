#include"AntManager.h"


//===================================
//初期化(アリ数設定)
//===================================
void AntManager::Init(int count)
{
	ants.resize(count);
}

//===================================
//更新(アリの更新)
//===================================
void AntManager::Update(float dt)
{
	for (auto& ant : ants)
	{
		ant.Update(dt);
	}
}

//===================================
//描画(アリの描画)
//===================================
void AntManager::Draw(int normalImage, int hitImage)
{
	for (auto& ant : ants)
	{
		ant.Draw(normalImage, hitImage);
	}
}

//===================================
//クリック処理(1回のみ有効)
//===================================
bool AntManager::HandClick(int mx, int my)
{
	for (auto& ant : ants)
	{
		if (ant.IsHit(mx, my))
		{
			return true;
		}
	}
	return false;
}