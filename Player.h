
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "FlyingObject.h"
#include "Ship.h"
#include "Model.h"

class Player : Ship
{
public:

	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	void Update();				// 更新メソッド
	void Draw() override;	    // 描画メソッド

	// プレイヤー操作
	void Control(float player_x, float player_y, unsigned int buttonMask);

private:

	Model *m_Model;
};
#endif // _PLAYER_
