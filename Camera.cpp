
#include "Camera.h"
#include "Vec3.h"
#include "glut.h"

Camera camera;

// コンストラクタ
Camera::Camera()
{
	position = Vec3(0, 0, 0);
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
		5, 5, 10,	// GLdouble eyex, eyey, eyez
		0, 0, 0,	// GLdouble centerx, centery, centerz
		0, 1, 0);	// GLdouble upx, upy, upz
}