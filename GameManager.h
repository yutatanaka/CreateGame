
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "Player.h"
#include "Field.h"

//　colorRGB
#define RED 0
#define GREEN 0
#define BLUE 1
#define ALPHA 1

// Perspective
#define FOVY 60
#define ASPECT 1
#define ZNEAR 0.1
#define ZFAR 100

// timer
#define MILLIS 1000 / 60
#define VALUE 0

enum Window
{
	Width = 1260,
	Height = 980,
};

class GameManager
{
public:

	// コンストラクタ
	GameManager();

	// デストラクタ
	~GameManager();

	// 初期化メソッド
	void Initialize();

	Player *player;

};

extern GameManager gameManager;

#endif  // _GAMEMANAGER_H_