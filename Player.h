
#ifndef _PLAYER_H_
#define _PLAYER_H_


#include "Ship.h"
#include "Model.h"

#define ANGLE_VALUE 0.03f

#define PLAYER_POSITION_X 0.2
#define PLAYER_POSITION_Y 0
#define PLAYER_POSITION_Z 0

#define PLAYER_ROTATION_X 0
#define PLAYER_ROTATION_Y 0
#define PLAYER_ROTATION_Z 0

#define PLAYER_SCALE_X 1
#define PLAYER_SCALE_Y 1
#define PLAYER_SCALE_Z 1

#define PLAYER_DIRECTION_X 0
#define PLAYER_DIRECTION_Y 0
#define PLAYER_DIRECTION_Z -1

#define PLAYER_NOW_ANGLE 0

#define PLAYER_SPEED  0.01

class Player : public Ship
{
public:

	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	/* �����]�����x */
	float INCREASE_ANGLE_VALUE;

	void Update();				// �X�V���\�b�h

	void Draw() override;	    // �`�惁�\�b�h

private:

	Model *m_Model;

	/* �ړ����� */
	void Move();

	/* ���͏��������� */
	void Input();

	/* �����Ă���p�x�������ɕ���(Vec3�^)���v�Z���� */
	void CalcDirection();

};

extern Player *player;

#endif // _PLAYER_
