
#include <math.h>
#include "Vec3.h"

// �R���X�g���N�^
Vec3::Vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

// �f�X�g���N�^
Vec3::~Vec3()
{
}

// �x�N�g���̋��������߂郁�\�b�h
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

// �x�N�g���𐳋K�����郁�\�b�h
float Vec3::Normalize()
{
	float normalize = 0;
	x = x / Length();
	y = y / Length();
	z = z / Length();

	return normalize;
}