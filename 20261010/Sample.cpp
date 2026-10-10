#include<iostream>
using namespace std;

//Playerクラスを定義
class Player
{
public:
	int hp = 100;
	//プレイヤーにダメージを与える関数
	void Damage()
	{
		hp -= 10;
	}
};

int main(void)
{
	//プレイヤーのオブジェクトをインスタンス化
	Player player;
	cout << "Player:HP" << player.hp << endl;

	//プレイヤーのオブジェクトのアドレスをポインタに保存する
	Player* pPlayer = &player;

	//ポインタを使ってDamage関数を呼び出すこともできます
	pPlayer->Damage();

	cout << "Player:HP" << player.hp << endl;

	return 0;
}