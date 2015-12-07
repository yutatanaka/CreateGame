
#ifndef _PLAYER_H_
#define _PLAYER_H_


#include "Ship.h"
#include "Model.h"

#define ANGLE_VALUE 0.03f

#define PLAYER_POSITION_X 0.2
#define PLAYER_POSITION_Y 0
#define PLAYER_POSITION_Z 0

#define PLAYER_ROTATION_X 0
#define PLAYER_ROTATION_Y 0
#define PLAYER_ROTATION_Z 0

#define PLAYER_SCALE_X 1
#define PLAYER_SCALE_Y 1
#define PLAYER_SCALE_Z 1

#define PLAYER_DIRECTION_X 0
#define PLAYER_DIRECTION_Y 0
#define PLAYER_DIRECTION_Z -1

#define PLAYER_NOW_ANGLE 0

#define PLAYER_SPEED  0.01

class Player : public Ship
{
public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	/* 方向転換速度 */
	float INCREASE_ANGLE_VALUE;

	void Update();				// 更新メソッド

	void Draw() override;	    // 描画メソッド

private:

	Model *m_Model;

	/* 移動処理 */
	void Move();

	/* 入力処理をする */
	void Input();

	/* もっている角度情報を元に方向(Vec3型)を計算する */
	void CalcDirection();

};

extern Player *player;

#endif // _PLAYER_
