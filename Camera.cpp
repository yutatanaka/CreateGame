
#include "Camera.h"
#include "Vec3.h"

Camera camera;

// コンストラクタ
Camera::Camera()
{
	camera.position = Vec3(0, 0, 0);
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
}