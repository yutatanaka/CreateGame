
#include "Player.h"
#define PLAYER_POSITION_X 0.2
#define PLAYER_POSITION_Y 0
#define PLAYER_POSITION_Z 0
#define PLAYER_DIRECTION_X 0
#define PLAYER_DIRECTION_Y 0
#define PLAYER_DIRECTION_Z 1
#define PLAYER_SPEED 5 

Player player;

// �R���X�g���N�^:�v���C���[������
Player::Player()
{
	// �����ʒu
	player.position.x = PLAYER_POSITION_X;
	player.position.y = PLAYER_POSITION_Y;
	player.position.z = PLAYER_POSITION_Z;

	// �����Ă����
	player.direction.x = PLAYER_DIRECTION_X;
	player.direction.y = PLAYER_DIRECTION_Y;
	player.direction.z = PLAYER_DIRECTION_Z;

	// �������x
	player.speed = PLAYER_SPEED;
};

// �f�X�g���N�^
Player::~Player()
{
};

// �X�V���\�b�h
void Player::Update()
{
}

// �`�惁�\�b�h
void Player::Draw()
{

}

// �v���C���[���상�\�b�h
void Player::Control(float player_x, float player_y, unsigned int buttonMask)
{

}
