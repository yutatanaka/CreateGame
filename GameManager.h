
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "Player.h"

class GameManager
{
public:

	// コンストラクタ
	GameManager();

	// デストラクタ
	~GameManager();

	Player *player;

	// 初期化メソッド
	void Initialize(); 

};

extern GameManager gameManager;

#endif  // _GAMEMANAGER_H_