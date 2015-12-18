
#include "Field.h"
#include "Vec3.h"
#include "glut.h"

Field field;

void Field::Update()
{

}

void Field::Draw()
{
	glColor3f(1, 1, 0);
	// ���̕`��
	glBegin(GL_LINES);
	{
		for (float z = -100.0; z <= 100.0; z += 1)
		{
			glVertex3f(-10, -1, z);
			glVertex3f(10, -1, z);

		}
		for (float x = -10.0; x <= 10.0; x += 1)
		{
			glVertex3f(x, -1, -100);
			glVertex3f(x, -1, 100);
		}
	}
	glEnd();

	// x�Ay�Az��
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100);

	}
	glEnd();
}