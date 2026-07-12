#include"Game.h"
#include"AntManager.h"
#include"DxLib.h"

/// ========================================================
/// 初期化
/// ========================================================
Game::Game()
{
	//スコアの初期化
	score = 0;

	backGround = LoadGraph("img/background.png");
	normalImage = LoadGraph("img/ant.png");
	hitImage = LoadGraph("img/ant_hit.png");
	//サウンド読み込み
	hitSound = LoadSoundMem("Sound/Punching_Sound.mp3");

	//アリを最初から複数用意
	antManager.Init(4);
}


/// ========================================================
///更新
/// ========================================================
void Game::Update(float dt, int mx, int my, bool click)
{
	antManager.Update(dt);
	if (click)
	{
		if (antManager.HandClick(mx, my))
		{
			//スコア加算
			score += 5;

			DrawFormatString(10, 10, GetColor(255, 255, 255), "Hit");
			PlaySoundMem(hitSound, DX_PLAYTYPE_BACK);
		}
	}
}
/// ========================================================
/// 描画
/// ========================================================
void Game::Draw()
{
	//背景を描画
	DrawGraph(0, 0, backGround, TRUE);
	antManager.Draw(normalImage, hitImage);
	SetFontSize(30);
	DrawFormatString(10, 10, GetColor(255, 255, 255), "Score:%d", score);
}