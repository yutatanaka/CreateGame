
#ifndef _FLYINGOBJECT_H_
#define _FLYINGOBJECT_H_

#include "Vec3.h"

class FlyingObject
{
public:

	// コンストラクタ
	FlyingObject();
	
	// デストラクタ
	~FlyingObject();

	Vec3 position; // 位置
	Vec3 direction;// 向いてる方向

	float speed;   // 速度

private:

	void Update();			   // 更新メソッド
	virtual void Draw() = 0;   // 描画メソッド
};



#endif  // FLYINGBJECT_H