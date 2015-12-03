
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "FlyingObject.h"
#include "Ship.h"
#include "Model.h"

class Player : Ship
{
public:

	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	void Update();				// �X�V���\�b�h
	void Draw() override;	    // �`�惁�\�b�h

	// �v���C���[����
	void Control(float player_x, float player_y, unsigned int buttonMask);

private:

	Model *m_Model;
};
#endif // _PLAYER_
