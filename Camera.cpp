
#include "Camera.h"
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
}

void Camera::Look()
{
	gluLookAt(
		5, 5, 10,							// GLdouble eyex, eyey, eyez
		position.x, position.y, position.z,	// GLdouble centerx, centery, centerz
		0, 1, 0);							// GLdouble upx, upy, upz
}