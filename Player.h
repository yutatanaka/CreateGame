
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

	// �X������������
	void Angle();

	// ���͏��������� 
	void Input();

	Model *m_Model;


	// �v���C���[�̍��W�̏����l(�萔)
	const float kPlayerPosition_x = 0.2f;
	const float kPlayerPosition_y = 0.0f;
	const float kPlayerPosition_z = 0.0f;

	// �v���C���[�̉�]�̏����l(�萔)
	const float kPlayerRotation_x = 0.0f;
	const float kPlayerRotation_y = 0.0f;
	const float kPlayerRotation_z = 0.0f;

	// �v���C���[�̃X�P�[���̏����l(�萔)
	const float kPlayerScale_x = 2.0f;
	const float kPlayerScale_y = 2.0f;
	const float kPlayerScale_z = 2.0f;

	// �v���C���[�̌����Ă�����̏����l(�萔)
	const float kPlayerDirection_x = 0.0f;
	const float kPlayerDirection_y = 0.0f;
	const float kPlayerDirection_z = -1.0f;

	// �v���C���[�̌��݂̊p�x�̏����l(�萔)
	const float kPlayerNowAngle = 0;

	// �v���C���[�̑��x�̏����l(�萔)
	const float kPlayerSpeed = 0.0f;
};

extern Player *player;

#endif // _PLAYER_
