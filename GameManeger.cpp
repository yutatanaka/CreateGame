
#include "GameManager.h"
#include "Player.h"

GameManager gameManager;

// �R���X�g���N�^
GameManager::GameManager()
{
	player = nullptr;
}

// �f�X�g���N�^
GameManager::~GameManager()
{
	delete player;
}

// ������
void GameManager::Initialize()
{
	player = new Player();
}