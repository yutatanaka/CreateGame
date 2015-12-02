
#ifndef _SHIP_H_
#define _SHIP_H_

#include "FlyingObject.h"

class Ship : public FlyingObject
{
public:

	// �R���X�g���N�^
	Ship();
	// �f�X�g���N�^
	~Ship();

private:
	// �v���C���[����
	virtual void Control(float player_x, float player_y, unsigned int buttonMask) = 0;
};

#endif // _SHIP_H_