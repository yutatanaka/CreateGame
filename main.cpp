
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "glm\glm.hpp"
#include "glut.h"
#include "GameManager.h"
#include "Camera.h"
#include "Types.h"
#include "LoadFile.h"
#include "Model.h"
#include "Field.h"
#include "Vec3.h"
#include "FlyingObject.h"
#include "Ship.h"
#include "Player.h"
#include "KeyBoard.h"



void Display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION);// GLenum mode
	glLoadIdentity();
	gluPerspective(
		60,		// GLdouble fovy
		1,		// GLdouble aspect
		0.1,	// GLdouble zNear
		100);	// GLdouble zFar

	glMatrixMode(GL_MODELVIEW);// GLenum mode

	glLoadIdentity();

	camera.Look();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	
	/*static unsigned int frame = 0;
	frame++;
	glRotatef(frame, 0, 1, 0);*/

	gameManager.player->Draw();

	gameManager.player->Update();

	field.Draw();

	glFlush();
}

void timer(int value) 
{
	glutTimerFunc(1000 / 60, timer, 0);		
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{

	glutInit(&argc,argv);
	
	glutCreateWindow("title"); 

	glutDisplayFunc(Display);

	glutTimerFunc(
		0,// unsigned int millis
		timer,// void (GLUTCALLBACK *func)(int value)
		0);// int value

	glutKeyboardFunc(KeyBoard::PushUpdate);

	glutKeyboardUpFunc(KeyBoard::ReleaseUpdate);

	gameManager.Initialize();

	glutMainLoop();

}