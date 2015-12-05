
#include "Player.h"
#include "LoadFile.h"
#include "Model.h"
#include "KeyBoard.h"


// コンストラクタ:プレイヤー初期化
Player::Player()
{

	m_Model = new Model(new LoadFile("res/sf.x", "res/sf.bmp"));

	// 初期位置
	position.x = PLAYER_POSITION_X;
	position.y = PLAYER_POSITION_Y;
	position.z = PLAYER_POSITION_Z;

	// 向いてる方向
	direction.x = PLAYER_DIRECTION_X;
	direction.y = PLAYER_DIRECTION_Y;
	direction.z = PLAYER_DIRECTION_Z;

	// 倍率
	scale.x = PLAYER_SCALE_X;
	scale.y = PLAYER_SCALE_Y;
	scale.z = PLAYER_SCALE_Z;

	// 初期速度
	speed = PLAYER_SPEED;
};


// デストラクタ
Player::~Player()
{
	delete m_Model;
};


// 更新メソッド
void Player::Update()
{
	
	direction.Normalize();
	position += direction * speed;


	// プレイヤー座標(xz) + ( プレイヤーの逆向き(xz) * 離したい距離 ) + 高さ

	// Ｗキーを押したら
	// 自機を+45度まで上に傾ける
	if (KeyBoard::keyUp == true)
	{
		rotation.x++;

		if (rotation.x >= 45)
		{
			rotation.x = 45;
			rotation.x--;

			if (rotation.x <= 0)
			{
				rotation.x = 0;
			}
		}
	}

	// Ｓキーを押したら
	// 自機を-45度まで下に傾ける
	if (KeyBoard::keyDown == true)
	{
		rotation.x--;

		if (rotation.x <= -45)
		{
			rotation.x = -45;
			rotation.x++;

			if (rotation.x >= 0)
			{
				rotation.x = 0;
			}
		}
	}

	// Aキーを押したら
	// 自機をｚ軸45度まで傾ける
	if (KeyBoard::keyLeft == true)
	{
		rotation.z++;

		if (rotation.z >= 45)
		{
			rotation.z = 45;
			rotation.z--;

			if (rotation.z <= 0)
			{
				rotation.z = 0;
			}
		}
	}

	// Ⅾキーを押したら
	// 自機をｚ軸ｰ45度まで傾ける
	if (KeyBoard::keyRight == 1)
	{
		rotation.z--;

		if (rotation.z <= -45)
		{
			rotation.z = -45;
			rotation.z++;

			if (rotation.z >= 0)
			{
				rotation.z = 0;
			}
		}
	}
}


// 描画メソッド
void Player::Draw()
{
	m_Model->Draw(position,rotation,scale);
}



