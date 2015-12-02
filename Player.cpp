
#include "Player.h"
#define PLAYER_POSITION_X 0.2
#define PLAYER_POSITION_Y 0
#define PLAYER_POSITION_Z 0
#define PLAYER_DIRECTION_X 0
#define PLAYER_DIRECTION_Y 0
#define PLAYER_DIRECTION_Z 1
#define PLAYER_SPEED 5 

Player player;

// コンストラクタ:プレイヤー初期化
Player::Player()
{
	// 初期位置
	player.position.x = PLAYER_POSITION_X;
	player.position.y = PLAYER_POSITION_Y;
	player.position.z = PLAYER_POSITION_Z;

	// 向いてる方向
	player.direction.x = PLAYER_DIRECTION_X;
	player.direction.y = PLAYER_DIRECTION_Y;
	player.direction.z = PLAYER_DIRECTION_Z;

	// 初期速度
	player.speed = PLAYER_SPEED;
};

// デストラクタ
Player::~Player()
{
};

// 更新メソッド
void Player::Update()
{
}

// 描画メソッド
void Player::Draw()
{

}

// プレイヤー操作メソッド
void Player::Control(float player_x, float player_y, unsigned int buttonMask)
{

}
