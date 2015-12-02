
#ifndef _MODEL_H_
#define _MODEL_H_

#include "LoadFile.h"
#include "Vec3.h"

class Model
{
public:

	LoadFile *loadFile;

	// �R���X�g���N�^
	Model(LoadFile *fileData);
	// �f�X�g���N�^
	~Model();


	// �`�惁�\�b�h
	void Draw(Vec3 position, Vec3 rotation, Vec3 scale);
};

#endif // MODEL_H_