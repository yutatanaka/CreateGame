
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vec3.h"

class Camera
{
public:
	// �R���X�g���N�^
	Camera();
	// �f�X�g���N�^
	~Camera();

	Vec3 position;

	// �X�V���\�b�h
	void Update();
	// �J�������_���\�b�h
	void Look();
};

extern Camera camera;

#endif // _CAMERA_H_