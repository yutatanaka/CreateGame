
#include <stdlib.h>
#include "glut.h"
#include "Vec3.h"
#include "Player.h"
#include "LoadFile.h"
#include "Model.h"
#include "KeyBoard.h"


// コンストラクタ:プレイヤー初期化
Player::Player()
{

	m_Model = new Model(new LoadFile("res/sf.x", "res/sf.bmp"));


	// キャラクタの座標を初期化
	position.x = PLAYER_POSITION_X;
	position.y = PLAYER_POSITION_Y;
	position.z = PLAYER_POSITION_Z;

	rotation.x = PLAYER_ROTATION_X;
	rotation.y = PLAYER_ROTATION_Y;
	rotation.z = PLAYER_ROTATION_Z;

	// キャラクタの倍率を初期化
	scale.x = PLAYER_SCALE_X;
	scale.y = PLAYER_SCALE_Y;
	scale.z = PLAYER_SCALE_Z;

	// キャラクタの向いてる方向を初期化
	direction.x = PLAYER_DIRECTION_X;
	direction.y = PLAYER_DIRECTION_Y;
	direction.z = PLAYER_DIRECTION_Z;

	// キャラクタの現在の角度を初期化
	nowAngle = PLAYER_NOW_ANGLE;

	// キャラクタの速度を初期化
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
	
	Move();

	Input();



}


// 描画メソッド
void Player::Draw()
{
	m_Model->Draw(position,rotation,scale);
}


// 移動処理
void Player::Move()
{
	//CalcDirection();

	direction.Normalize();
	position += direction * speed;
}


void Player::Input()
{
	// Ｗキーを押したら
	// 自機を+45度まで上に傾ける
	if (KeyBoard::keyUp == true)
	{
		
		rotation.x++;

		if (rotation.x >= 45)
		{
			rotation.x = 45;
			rotation.x--;

			if (rotation.x <= -1)
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

			if (rotation.x >= 1)
			{
				rotation.x = 0;
			}
		}
	}

	// Aキーを押したら
	// 自機をｚ軸45度まで傾ける
	if (KeyBoard::keyLeft == true)
	{
		nowAngle += INCREASE_ANGLE_VALUE;
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
		nowAngle -= INCREASE_ANGLE_VALUE;
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


void Player::CalcDirection()
{
	//角度をx,y,z方向の要素に分解 
	direction.x = (sin(nowAngle), 0 , cos(nowAngle));

	//direction.z = (sin(nowAngle), 0 , cos(nowAngle));
}
