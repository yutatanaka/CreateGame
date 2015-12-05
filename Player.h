
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "FlyingObject.h"
#include "Ship.h"
#include "Model.h"

#define PLAYER_POSITION_X 0.2
#define PLAYER_POSITION_Y 0
#define PLAYER_POSITION_Z 0
#define PLAYER_DIRECTION_X 0
#define PLAYER_DIRECTION_Y 0
#define PLAYER_DIRECTION_Z -1
#define PLAYER_SCALE_X 1
#define PLAYER_SCALE_Y 1
#define PLAYER_SCALE_Z 1
#define PLAYER_SPEED  0.01

class Player : public Ship
{
public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	void Update();				// 更新メソッド
	void Draw() override;	    // 描画メソッド

	// プレイヤー操作
	void Control(float player_x, float player_y, unsigned int buttonMask);

private:

	Model *m_Model;
};

extern Player *player;

#endif // _PLAYER_
