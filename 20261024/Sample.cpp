#include<iostream>
#include<vector>

//class Enemy
//{
//public:
//	Enemy();
//	~Enemy();
//
//private:
//
//};

int main(void)
{
	/*Enemy enemy;*/
	//ƒxƒNƒ^[‚ğéŒ¾
	std::vector<int> number;	//<>Ši”[‚·‚éŒ^
	std::vector<float>number2;
	/*std::vector<Enemy>enemies;*/
	//’Ç‰Á
	number.push_back(10);
	number.push_back(20);
	number.push_back(30);
	//—v‘f”Šm”F
	std::cout << number.size() << std::endl;
	//
	int num = number[0];
	std::cout << num;
	//íœ
	number.clear();

	return 0;
}