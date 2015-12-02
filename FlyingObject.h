
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
	Vec3 rotation; // 回転
	Vec3 scale;	  
	Vec3 direction;// 向いてる方向

	float speed;   // 速度

	void Update();			   // 更新メソッド
	virtual void Draw() = 0;   // 描画メソッド
private:

};



#endif  // FLYINGBJECT_H