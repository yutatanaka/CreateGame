
#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>

class Vec3
{
public:
	float x, y, z;

	// コンストラクタ
	Vec3(){
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	};

	// デストラクタ
	~Vec3(){};

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

	Vec3& operator *(const float v)
	{
		x * v;
		y * v;
		z * v;

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

	float Length()
	{
		float length =
			sqrt(
			x * x
			+ y * y
			+ z * z
			);

		return length;
	}

	float Normalize()
	{
		float normalize = 0;
		x = x / Length();
		y = y / Length();
		z = z / Length();

		return normalize;
	}

};

#endif // _VEC3_H_