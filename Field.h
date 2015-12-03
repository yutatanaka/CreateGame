
#ifndef _FIELD_H_
#define _FIELD_H_

#include "Vec3.h"

class Field
{
public: 

	Vec3 position;

	void Update();
	void Draw();

};

extern Field field;

#endif  // _FIELD_H_