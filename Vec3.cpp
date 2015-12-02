
#include <math.h>
#include "Vec3.h"

// コンストラクタ
Vec3::Vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

// デストラクタ
Vec3::~Vec3()
{
}

// ベクトルの距離を求めるメソッド
float Vec3::Length()
{
	float length =
		sqrt(
		x * x
		+ y * y
		+ z * z
		);

	return length;
}

// ベクトルを正規化するメソッド
float Vec3::Normalize()
{
	float normalize = 0;
	x = x / Length();
	y = y / Length();
	z = z / Length();

	return normalize;
}