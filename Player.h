
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Ship.h"
#include "Model.h"

class Player : public Ship
{
public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();


	void Update();				// 更新メソッド

	void Draw() override;	    // 描画メソッド

private:

	// 移動処理をする
	void Move();

	// 入力処理をする 
	void Input();

	// もっている角度情報を元に方向(Vec3型)を計算する 
	void CalcDirection();


	Model *m_Model;

	// 方向転換速度 
	const float INCREASE_ANGLE_VALUE = 0;

	// プレイヤーの座標の初期値(定数)
	const float kPlayerPosition_x = 0.2f;
	const float kPlayerPosition_y = 0.0f;
	const float kPlayerPosition_z = 0.0f;

	// プレイヤーの回転の初期値(定数)
	const float kPlayerRotation_x = 0.0f;
	const float kPlayerRotation_y = 0.0f;
	const float kPlayerRotation_z = 0.0f;

	// プレイヤーのスケールの初期値(定数)
	const float kPlayerScale_x = 1.0f;
	const float kPlayerScale_y = 1.0f;
	const float kPlayerScale_z = 1.0f;

	// プレイヤーの向いてる方向の初期値(定数)
	const float kPlayerDirection_x = 0.0f;
	const float kPlayerDirection_y = 0.0f;
	const float kPlayerDirection_z = -1.0f;

	// プレイヤーの現在の角度の初期値(定数)
	const float kPlayerNowAngle = 0;

	// プレイヤーの速度の初期値(定数)
	const float kPlayerSpeed = 0.5f;
};

extern Player *player;

#endif // _PLAYER_
