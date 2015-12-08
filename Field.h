
#ifndef _FIELD_H_
#define _FIELD_H_

#include "Vec3.h"

class Field
{
public: 

	void Update();
	void Draw();

	Vec3 position;

};

extern Field field;

#endif  // _FIELD_H_