
#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>

class Vec3
{
public:
	float x, y, z;
	
	// コンストラクタ
	Vec3();

	// デストラクタ
	~Vec3();

	Vec3(float x_axis, float y_axis, float z_axis)
	{
		x = x_axis;
		y = x_axis;
		z = x_axis;
	}

	Vec3& operator +(const Vec3 vector)
	{
		x + vector.x;
		y + vector.y;
		z + vector.z;
	}


	Vec3& operator -(const Vec3 vector)
	{
		x + vector.x;
		y + vector.y;
		z + vector.z;
	}

	Vec3& operator *(const Vec3 vector)
	{
		x * vector.x;
		y * vector.y;
		z * vector.z;
	}

	Vec3& operator *(const float vector)
	{
		x * vector;
		y * vector;
		z * vector;

		return *this;
	}


	Vec3& operator +=(const Vec3 vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return *this;
	}


	Vec3& operator -=(const Vec3 vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return *this;
	}


	Vec3& operator *=(const Vec3 vector)
	{
		x *= vector.x;
		y *= vector.y;
		z *= vector.z;

		return *this;
	}

	// ベクトルの距離を求めるメソッド
	float Length();

	// ベクトルを正規化するメソッド
	float Normalize();

};

#endif // _VEC3_H_