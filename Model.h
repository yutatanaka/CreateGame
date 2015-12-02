
#ifndef _MODEL_H_
#define _MODEL_H_

#include "LoadFile.h"
#include "Vec3.h"

class Model
{
public:

	LoadFile *loadFile;

	// コンストラクタ
	Model(LoadFile *fileData);
	// デストラクタ
	~Model();


	// 描画メソッド
	void Draw(Vec3 position, Vec3 rotation, Vec3 scale);
};

#endif // MODEL_H_