
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "glm\glm.hpp"
#include "glut.h"
#include "Types.h"
#include "LoadFile.h"
#include "Vec3.h"
#include "FlyingObject.h"
#include "Ship.h"
#include "Player.h"

unsigned int nVertices;
unsigned int nIndices;
unsigned int nNormals;
unsigned int nTextureCoords;

// キーボード変数
bool keyUp = false;
bool keyDown = false;
bool keyLeft = false;
bool keyRight = false;
bool keySpace = false;
bool lastSpaceKey = false;

// 回転変数
float rotate_x = 0;
float rotate_y = 0;
float rotate_z = 0;

// キーが押された時の関数
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': // wキー
		keyUp = true; break;
	case 's': // sキー
		keyDown = true; break;
	case 'a': // aキー
		keyLeft = true; break;
	case 'd': // dキー
		keyRight = true; break;
	case ' ': // spaceキー
		keySpace = true; break;
	}
}

// キーが離された時の関数
void keyboardUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': // wキー
		keyUp = false;    break;
	case 's': // sキー
		keyDown = false;  break;
	case 'a': // aキー
		keyLeft = false;  break;
	case 'd': // dキー
		keyRight = false; break;
	case ' ': // spaceキー
		keySpace = false; break;
	}
}



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

	gluLookAt(
		5, 5, 10,	// GLdouble eyex, eyey, eyez
		0, 0, 0,	// GLdouble centerx, centery, centerz
		0, 1, 0);	// GLdouble upx, upy, upz

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	
	static unsigned int frame = 0;
	frame++;
	glRotatef(frame, 0, 1, 0);

	// テクスチャデータをVARMに転送
	glTexImage2D(
		GL_TEXTURE_2D,			//GLenum target
		0,						//GLint level
		GL_RGB,					//GLint internalformat
		bitMapInfo.biWidth, bitMapInfo.biHeight,				//GLsizei width, height
		0,						//GLint border
		GL_RGB,					//GLenum format
		GL_UNSIGNED_BYTE,		//GLenum type
		pixels);				//const GLvoid *pixels

	GLint filter =
		GL_NEAREST;

	//テクチャを縮小表示したときのフィルター
	glTexParameteri(
		GL_TEXTURE_2D,			//GLenum target
		GL_TEXTURE_MIN_FILTER,	//GLenum pname
		filter);				//GLint param

	// テクスチャを拡大表示したときのフィルター
	glTexParameteri(
		GL_TEXTURE_2D,			//GLenum target
		GL_TEXTURE_MAG_FILTER,	//GLenum pname
		filter);				//GLint param

	// 床の描画
	glBegin(GL_LINES);
	{
		for (float z = -100.0; z <= 100.0; z += 1)
		{
			glVertex3f(-10, 0, z);
			glVertex3f(10, 0, z);

		}
		for (float x = -10.0; x <= 10.0; x += 1)
		{
			glVertex3f(x, 0, -100);
			glVertex3f(x, 0, 100);
		}
	}
	glEnd();

	glBegin(GL_LINES);
	{
	
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);

		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100);

	}
	glEnd();

	glPushMatrix();
	{
		glTranslatef(0.2, 0, 0);

		// Ｗキーを押したら
		// 自機を+45度まで上に傾ける
		if (keyUp == true)
		{
			rotate_x++;

			if (rotate_x >= 45)
			{
				rotate_x = 45;
				rotate_x--;
				
				if (rotate_x<= 0)
				{
					rotate_x = 0;
				}
			}
		}

		// Ｓキーを押したら
		// 自機を-45度まで下に傾ける
		if (keyDown == true)
		{
			rotate_x--;

			if (rotate_x <= -45)
			{
				rotate_x = -45;
				rotate_x++;

				if (rotate_x >= 0)
				{
					rotate_x = 0;
				}
			}
		}

		// Aキーを押したら
		// 自機をｚ軸45度まで傾ける
		if (keyLeft == true)
		{
			rotate_z++;

			if (rotate_z >= 45)
			{
				rotate_z = 45;
				rotate_z--;

				if (rotate_z <= 0)
				{
					rotate_z = 0;
				}
			}
		}

		// Ⅾキーを押したら
		// 自機をｚ軸ｰ45度まで傾ける
		if (keyRight == 1)
		{
			rotate_z--;

			if (rotate_z <= -45)
			{
				rotate_z = -45;
				rotate_z++;

				if (rotate_z >= 0)
				{
					rotate_z = 0;
				}
			}
		}
	
		// X軸回転
		glRotatef(rotate_x, 1, 0, 0);

		// Z軸回転
		glRotatef(rotate_z, 0, 0, 1);

		glEnable(GL_TEXTURE_2D);
		
		// 頂点座標配列を有効にする
		glEnableClientState(GL_VERTEX_ARRAY);
		
		// インデックス配列を有効にする
		glEnableClientState(GL_INDEX_ARRAY);
		
		// 法線配列を有効にする
		glEnableClientState(GL_NORMAL_ARRAY);
		
		// テクスチャ配列を有効にする
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		// テクスチャデータをセット
		
		glTexCoordPointer(
			2,
			GL_FLOAT,
			0,
			textureCoords);
		
		// 頂点データをセット
		glVertexPointer(
			3,
			GL_FLOAT,
			0,
			vertices);
		
		// 法線データをセット
		glNormalPointer(
			GL_FLOAT,
			0,
			normals);

		// インデックスデータをセット
		glDrawElements(
			GL_TRIANGLES,
			nIndices * 3,
			GL_UNSIGNED_INT,
			indices);
	}
	glPopMatrix();
	
	glFlush();
}

void timer(int value) 
{
	glutTimerFunc(1000 / 60, timer, 0);		
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{

	loadFile.LoadXFile("res/sf.x");

	loadFile.LoadTextureFile("res/sf.bmp");

	loadFile.CreateNormals();

	glutInit(
		&argc,					// int *argcp
		argv);					// char **argv
	glutCreateWindow("title");  // const char *title

	glutDisplayFunc(Display);	// void (GLUTCALLBACK *func)(void)

	glutTimerFunc(
		0,// unsigned int millis
		timer,// void (GLUTCALLBACK *func)(int value)
		0);// int value

	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMainLoop();

	free (textureCoords);
	free (normals);
	free (indices);
	free (vertices);
}