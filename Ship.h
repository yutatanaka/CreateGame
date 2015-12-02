
#ifndef _SHIP_H_
#define _SHIP_H_

#include "FlyingObject.h"

class Ship : public FlyingObject
{
public:

	// コンストラクタ
	Ship();
	// デストラクタ
	~Ship();

	// プレイヤー操作
	virtual void Control(float player_x, float player_y, unsigned int buttonMask) = 0;
private:
};

#endif // _SHIP_H_