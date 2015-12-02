
#ifndef _VEC3_H_
#define _VEC3_H_

#include <math.h>

class Vec3
{
public:
	float x, y, z;
	
	// �R���X�g���N�^
	Vec3();

	// �f�X�g���N�^
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

	// �x�N�g���̋��������߂郁�\�b�h
	float Length();

	// �x�N�g���𐳋K�����郁�\�b�h
	float Normalize();

};

#endif // _VEC3_H_