
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "Player.h"

class GameManager
{
public:

	// �R���X�g���N�^
	GameManager();

	// �f�X�g���N�^
	~GameManager();

	Player *player;

	// ���������\�b�h
	void Initialize(); 

};

extern GameManager gameManager;

#endif  // _GAMEMANAGER_H_