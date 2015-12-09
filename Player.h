
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Ship.h"
#include "Model.h"

class Player : public Ship
{
public:

	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();


	void Update();				// �X�V���\�b�h

	void Draw() override;	    // �`�惁�\�b�h

private:

	// �ړ�����������
	void Move();

	// ���͏��������� 
	void Input();

	// �����Ă���p�x�������ɕ���(Vec3�^)���v�Z���� 
	void CalcDirection();


	Model *m_Model;

	// �����]�����x 
	const float INCREASE_ANGLE_VALUE = 0;

	// �v���C���[�̍��W�̏����l(�萔)
	const float kPlayerPosition_x = 0.2f;
	const float kPlayerPosition_y = 0.0f;
	const float kPlayerPosition_z = 0.0f;

	// �v���C���[�̉�]�̏����l(�萔)
	const float kPlayerRotation_x = 0.0f;
	const float kPlayerRotation_y = 0.0f;
	const float kPlayerRotation_z = 0.0f;

	// �v���C���[�̃X�P�[���̏����l(�萔)
	const float kPlayerScale_x = 1.0f;
	const float kPlayerScale_y = 1.0f;
	const float kPlayerScale_z = 1.0f;

	// �v���C���[�̌����Ă�����̏����l(�萔)
	const float kPlayerDirection_x = 0.0f;
	const float kPlayerDirection_y = 0.0f;
	const float kPlayerDirection_z = -1.0f;

	// �v���C���[�̌��݂̊p�x�̏����l(�萔)
	const float kPlayerNowAngle = 0;

	// �v���C���[�̑��x�̏����l(�萔)
	const float kPlayerSpeed = 0.5f;
};

extern Player *player;

#endif // _PLAYER_
