
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
	position.x = kPlayerPosition_x;
	position.y = kPlayerPosition_y;
	position.z = kPlayerPosition_z;

	// キャラクタの回転の値を初期化
	rotation.x = kPlayerRotation_x;
	rotation.y = kPlayerRotation_y;
	rotation.z = kPlayerRotation_z;

	// キャラクタの倍率を初期化
	scale.x = kPlayerScale_x;
	scale.y = kPlayerScale_y;
	scale.z = kPlayerScale_z;

	// キャラクタの向いてる方向を初期化
	direction.x = kPlayerDirection_x;
	direction.y = kPlayerDirection_y;
	direction.z = kPlayerDirection_z;

	// キャラクタの現在の角度を初期化
	nowAngle = kPlayerNowAngle;

	// キャラクタの速度を初期化
	speed = kPlayerSpeed;
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
	// 自機を+20度まで上に傾ける
	if (KeyBoard::keyUp == true)
	{
		
		rotation.x++;

		if (rotation.x >= 20)
		{
			rotation.x = 20;
			rotation.x--;

			if (rotation.x <= -1)
			{
				rotation.x = 0;
			}
		}
	}


	glRotatef(rotation.x, 1, 0, 0);

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
