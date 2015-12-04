
#include "GameManager.h"
#include "Player.h"

GameManager gameManager;

// コンストラクタ
GameManager::GameManager()
{
	player = nullptr;
}

// デストラクタ
GameManager::~GameManager()
{
	delete player;
}

// 初期化
void GameManager::Initialize()
{
	player = new Player();
}