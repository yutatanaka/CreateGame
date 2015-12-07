
#include <stdio.h>
#include "Camera.h"
#include "GameManager.h"
#include "Vec3.h"
#include "Player.h"
#include "glut.h"


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
	const float releaseDistance = 10.0f;
	const int cameraY_axis = 0;

	// プレイヤー座標(xz) + ( プレイヤーの逆向き(xz) * 離したい距離 ) + 高さ

	position = gameManager.player->direction;

	position.x = -position.x;
	position.z = -position.z;
	position.y = cameraY_axis;

	position.x *= releaseDistance;
	position.z *= releaseDistance;
	position.y *= releaseDistance;

	position.x += gameManager.player->position.x;
	position.z += gameManager.player->position.z;
	printf("%f\n", position.z);
}

void Camera::Look()
{
	const int cameraWidth = 5;
	const int cameraUpx = 0;
	const int cameraUpy = 1;
	const int cameraUpz = 0;
	
	gluLookAt(
		position.x, position.y + cameraWidth, position.z,			// GLdouble eyex, eyey, eyez
		gameManager.player->position.x,
		gameManager.player->position.y,
		gameManager.player->position.z,				// GLdouble centerx, centery, centerz
		cameraUpx, cameraUpy, cameraUpz);									// GLdouble upx, upy, upz
}