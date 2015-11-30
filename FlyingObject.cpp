
#include "FlyingObject.h"

FlyingObject::FlyingObject()
{
	position = Vec3(0, 0, 0);
	direction = Vec3(0, 0, 0);
	speed = 0;
}

void FlyingObject::Update()
{
	direction.Normalize();
	position += direction * speed;
};


void FlyingObject::Draw()
{
};