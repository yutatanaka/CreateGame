
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
#include "Ship.h"
#include "Player.h"
#include "KeyBoard.h"



void Display(void){
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glClearColor(RED, GREEN, BLUE, ALPHA);
	
	glMatrixMode(GL_PROJECTION);// GLenum mode
	
	glLoadIdentity();
	
	gluPerspective(
		FOVY,		// GLdouble fovy
		ASPECT,		// GLdouble aspect
		ZNEAR,	// GLdouble zNear
		ZFAR);	// GLdouble zFar

	glMatrixMode(GL_MODELVIEW);// GLenum mode

	glLoadIdentity();

	camera.Update();

	camera.Look();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	
	glPushMatrix();
	{
		gameManager.player->Draw();

		gameManager.player->Update();

	}
	glPopMatrix();

	glPushMatrix();
	{
		field.Draw();
	}
	glPopMatrix();

	glFlush();
}

void timer(int value) 
{
	glutTimerFunc(MILLIS, timer, VALUE);		
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