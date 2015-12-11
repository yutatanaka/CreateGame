
#ifndef _SHIP_H_
#define _SHIP_H_

#include "Vec3.h"

class Ship
{
public:

	// コンストラクタ
	Ship();
	// デストラクタ
	~Ship();

	virtual void Update();	   // 更新メソッド
	virtual void Draw() = 0;   // 描画メソッド

	Vec3 position;  // 位置

	Vec3 rotation;  // 回転

	Vec3 scale;	    // 倍率

	Vec3 direction; // 向いてる方向

	float nowAngle; // 現在の角度

	float speed;    // 速度

};

#endif // _SHIP_H_