#include "Game.h"
#include"DxLib.h"

//
//
//
void Game::Init()
{
	//
	//
	//
	background.Init();
	//
	objects.emplace_back(100, 300);
	objects.emplace_back(500, 300);
	objects.emplace_back(1000, 300);
	objects.emplace_back(1500, 300);
}

//
//
//
void Game::Update()
{
	//
	//
	//
	camera.Update();
}

//
//
//
void Game::Draw()
{
	//
	//
	//
	background.Draw(camera.GetX());

	//
	//
	//
	for (auto& obj : objects)
	{
		obj.Draw(camera.GetX());
	}

	//
	//
	//
	DrawFormatString(20, 20, GetColor(255, 255, 0), "CameraX : %.0f", camera.GetX());
}