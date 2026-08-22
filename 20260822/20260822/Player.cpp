#include "Player.h"
#include"Map.h"
#include"Dxlib.h"

namespace
{
	//========================================================
	//アニメーション方向
	//========================================================

	constexpr int ANIM_DOWN = 0;
	constexpr int ANIM_LEFT = 1;
	constexpr int ANIM_RIGHT = 2;
	constexpr int ANIM_UP = 3;
}

//========================================================
//コンストラクタ
//========================================================

Player::Player()
{
	x = 0.0f;
	y = 0.0f;

	velocityX = 0.0f;
	velocityY = 0.0f;

	animTimer = 0.0f;

	animNowType = ANIM_DOWN;
	animNowPattern = 1;
	animNowIndex = 1;

	drawOffsetX = 0;
	drawOffsetY = 0;

	for (int i = 0; i < Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM; i++)
	{
		playerImg[i] = -1;
	}
}

//========================================================
//デストラクタ
//========================================================

Player::~Player()
{
	for (int i = 0; i < Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM; i++)
	{
		if (playerImg[i] != -1)
		{
			DeleteGraph(playerImg[i]);

			playerImg[i] = -1;
		}
	}
}

//========================================================
//初期化
//========================================================

bool Player::Init()
{
	//========================================================
	//初期座標
	//========================================================

	x = Config::PLAYER_START_X;
	y = Config::PLAYER_START_Y;

	velocityX = 0.0f;
	velocityY = 0.0f;

	animTimer = 0.0f;

	animNowType = ANIM_DOWN;
	animNowPattern = 1;

	animNowIndex = animNowPattern + animNowType * Config::ANIM_PATTERN_NUM;

	//========================================================
	//画像読み込み
	//========================================================

	int result = LoadDivGraph(Config::PLAYER_IMAGE_PATH, Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM,
		Config::ANIM_PATTERN_NUM, Config::ANIM_TYPE_NUM, Config::PLAYER_IMAGE_SIZE_X, Config::PLAYER_IMAGE_SIZE_Y, playerImg);

	if (result != 0)
	{
		return false;
	}

	//========================================================
	//描画位置補正
	//========================================================

	drawOffsetX = (Config::PLAYER_HIT_SIZE_X - Config::PLAYER_IMAGE_SIZE_X) / 2;

	drawOffsetY = Config::PLAYER_HIT_SIZE_Y - Config::PLAYER_IMAGE_SIZE_Y;

	return true;
}

//========================================================
//更新
//========================================================

void Player::Update(float deltaTime, const Map& mmap)
{
	//========================================================
	//速度をリセット
	//========================================================

	velocityX = 0.0f;
	velocityY = 0.0f;

	bool isMove = false;

	//========================================================
	//キー入力
	//========================================================

	if(CheckHitKey(KEY_INPUT_UP))
	{
		velocityY = -Config::PLAYER_MOVE_SPEED;

		animNowType = ANIM_UP;

		isMove = true;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		velocityX = -Config::PLAYER_MOVE_SPEED;

		animNowType = ANIM_DOWN;

		isMove = true;
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		velocityX = -Config::PLAYER_MOVE_SPEED;

		animNowType = ANIM_LEFT;

		isMove = true;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		velocityX = -Config::PLAYER_MOVE_SPEED;

		animNowType = ANIM_RIGHT;

		isMove = true;
	}

	//========================================================
	//移動量
	//========================================================

	float moveX = velocityX * deltaTime;

	float moveY = velocityY * deltaTime;

	//========================================================
	//X方向移動
	//========================================================

	x += moveX;

	map.ResolveHorizonalCollision(x, y, Config::PLAYER_HIT_SIZE_X, Config::PLAYER_HIT_SIZE_Y, moveX);

}