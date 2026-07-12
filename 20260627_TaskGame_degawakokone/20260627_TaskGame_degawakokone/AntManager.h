#pragma once
#include<vector>
#include"Ant.h"

//=================================================
// アリの複数管理クラス
// ・初期化
// ・更新
// ・描画
// ・クリック判定の集約
//=================================================

class AntManager
{
private:
	//アリの数を保持
	std::vector<Ant>ants;
public:
	//アリ生成
	void Init(int count);

	//アリ更新
	void Update(float dt);

	//アリ描画
	void Draw(int normalImage, int hitImage);

	//全アリクリア判定
	bool HandClick(int mx, int my);

};

