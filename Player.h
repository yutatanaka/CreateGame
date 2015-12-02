
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "FlyingObject.h"
#include "Ship.h"

class Player : Ship
{
public:

	Player();
	~Player();

private:

	void Update();				// 更新メソッド
	void Draw() override;	    // 描画メソッド

	// プレイヤー操作
	void Control(float player_x, float player_y, unsigned int buttonMask);
};

extern Player player;

#endif // _PLAYER_
