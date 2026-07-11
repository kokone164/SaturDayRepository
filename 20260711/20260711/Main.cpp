#include"Dxlib.h"
#include"Game.h"
#include"Config.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	ChangeWindowMode(TRUE);
	SetWindowSize(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
	//
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	Game game;

	game.Init();

	//
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//
		ClearDrawScreen();
		//
		game.Update();
		//
		game.Draw();
		//
		ScreenFlip();
	}

	//DXライブラリ終了処理
	DxLib_End();
	//正常終了
	return 0;
}