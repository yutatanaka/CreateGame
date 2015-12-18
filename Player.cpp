
#include <stdio.h>
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

	Angle();

}


// 描画メソッド
void Player::Draw()
{
	m_Model->Draw(position,rotation,scale);
}


// 移動処理
void Player::Move()
{

	direction.Normalize();

	Input();
	//position += direction * speed;

}

// 傾き処理
void Player::Angle()
{
	//if (KeyBoard::keyRight == true)
	//{
	//	rotation.z -= 15.0f;
	//	glRotatef(rotation.z, 0, 0, 1);
	//}
	//else
	//{
	//	rotation.z = 0;
	//}
}

// 入力処理
void Player::Input()
{
	// キーボードのDが押されたら
	if (KeyBoard::keyRight == true)
	{
		position.x += speed;
	}

	// キーボードのAが押されたら
	if (KeyBoard::keyLeft == true)
	{
		position.x -= speed;
	}

	// キーボードのWが押されたら
	if (KeyBoard::keyUp == true)
	{
		position.z -= speed;
	}

	// キーボードのSが押されたら
	if (KeyBoard::keyDown == true)
	{
		position.z += speed;
	}
}

