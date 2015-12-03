
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vec3.h"

class Camera
{
public:
	// コンストラクタ
	Camera();
	// デストラクタ
	~Camera();

	Vec3 position;

	// 更新メソッド
	void Update();
	// カメラ視点メソッド
	void Look();
};

extern Camera camera;

#endif // _CAMERA_H_