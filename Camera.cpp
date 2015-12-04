
#include <stdio.h>
#include "Camera.h"
#include "GameManager.h"
#include "Vec3.h"
#include "FlyingObject.h"
#include "Player.h"
#include "glut.h"

#define M_PI 3.141592

Camera camera;

// コンストラクタ
Camera::Camera()
{

}

// デストラクタ
Camera::~Camera()
{
	
}


void Camera::Update()
{

	// プレイヤー座標(xz) + ( プレイヤーの逆向き(xz) * 離したい距離 ) + 高さ

	position = gameManager.player->direction;

	position.x = -position.x;
	position.z = -position.z;
	position.y = 0;

	position.x *= 10.0f;
	position.z *= 10.0f;
	position.y *= 10.0f;

	position.x += gameManager.player->position.x;
	position.z += gameManager.player->position.z;
	printf("%f\n", position.z);
}

void Camera::Look()
{
	gluLookAt(
		position.x, position.y + 5, position.z,			// GLdouble eyex, eyey, eyez
		gameManager.player->position.x,
		gameManager.player->position.y,
		gameManager.player->position.z,				// GLdouble centerx, centery, centerz
		0, 1, 0);									// GLdouble upx, upy, upz
}