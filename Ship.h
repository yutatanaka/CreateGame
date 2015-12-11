
#ifndef _SHIP_H_
#define _SHIP_H_

#include "Vec3.h"

class Ship
{
public:

	// �R���X�g���N�^
	Ship();
	// �f�X�g���N�^
	~Ship();

	virtual void Update();	   // �X�V���\�b�h
	virtual void Draw() = 0;   // �`�惁�\�b�h

	Vec3 position;  // �ʒu

	Vec3 rotation;  // ��]

	Vec3 scale;	    // �{��

	Vec3 direction; // �����Ă����

	float nowAngle; // ���݂̊p�x

	float speed;    // ���x

};

#endif // _SHIP_H_