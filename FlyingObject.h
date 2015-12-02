
#ifndef _FLYINGOBJECT_H_
#define _FLYINGOBJECT_H_

#include "Vec3.h"

class FlyingObject
{
public:

	// �R���X�g���N�^
	FlyingObject();
	
	// �f�X�g���N�^
	~FlyingObject();

	Vec3 position; // �ʒu
	Vec3 direction;// �����Ă����

	float speed;   // ���x

private:

	void Update();			   // �X�V���\�b�h
	virtual void Draw() = 0;   // �`�惁�\�b�h
};



#endif  // FLYINGBJECT_H