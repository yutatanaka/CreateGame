
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "glm\glm.hpp"
#include "glut.h"
#include "Types.h"
#include "LoadTexture.h"

using namespace glm;

unsigned int nVertices;
unsigned int nIndices;
unsigned int nNormals;
unsigned int nTextureCoords;

unsigned int keyUp;
unsigned int keyDown;
unsigned int keyLeft;
unsigned int keyRight;
unsigned int keySpace;
unsigned int lastSpaceKey;

float rotate_x = 0;

class Player
{
public:
	float x, y, z;
};
Player player;



void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		keyUp = 1; break;
	case 's':
		keyDown = 1; break;
	case 'a':
		keyLeft = 1; break;
	case 'd':
		keyRight = 1; break;
	case ' ':
		keySpace = 1; break;
	}

}

void keyboardUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		keyUp = 0; break;
	case 's':
		keyDown = 0; break;
	case 'a':
		keyLeft = 0; break;
	case 'd':
		keyRight = 0; break;
	case ' ':
		keySpace = 0; break;
	}

}

void LoadTextureFile()
{
	FILE *pFile = fopen(
		"res/sf.bmp",
		"rb");
	assert(pFile != NULL);

	fread(
		&bitMapFile,
		sizeof(BITMAPFILEHEADER),
		1,
		pFile);
	fread(
		&bitMapInfo,
		sizeof(BITMAPINFOHEADER),
		1,
		pFile);

	int size = bitMapInfo.biWidth * bitMapInfo.biHeight * sizeof(TextureRGB);
	pixels = (TextureRGB*)malloc(bitMapInfo.biWidth * bitMapInfo.biHeight * sizeof(TextureRGB));

	fread(
		pixels,
		size,
		1,
		pFile);

	fclose(pFile);

	for (int y = 0; y < bitMapInfo.biHeight; y++)
	{
		for (int x = 0; x < bitMapInfo.biWidth; x++)
		{
			unsigned char pixelsbox;
			pixelsbox = pixels[bitMapInfo.biWidth * y + x].red;
			pixels[bitMapInfo.biWidth * y + x].red = pixels[bitMapInfo.biWidth * y + x].blue;
			pixels[bitMapInfo.biWidth * y + x].blue = pixelsbox;
		}
	}

	for (int y = 0; y < bitMapInfo.biHeight / 2; y++)
	{
		for (int x = 0; x < bitMapInfo.biWidth; x++)
		{
			TextureRGB pixelsbox;
			pixelsbox = pixels[bitMapInfo.biWidth * y + x];
			pixels[bitMapInfo.biWidth * y + x] = pixels[bitMapInfo.biWidth * (bitMapInfo.biHeight - 1 - y) + x];
			pixels[bitMapInfo.biWidth * (bitMapInfo.biHeight - 1 - y) + x] = pixelsbox;
		}
	}
}

// Xファイルを読み込む関数
void LoadXFile()
{
	FILE *pFile = fopen("res/sf.x", "r");
	assert(pFile != NULL);

	char buf[256];
	char buf1[256];
	int n;

	while (1){
		n = fscanf(pFile, "%s", &buf);
		if (n < 1)
			break;
		if (strcmp(buf, "template") == 0){
			while (strcmp(buf, "}") != 0){
				n = fscanf(pFile, "%s", &buf);
			}
		}
		if (strcmp(buf, "Mesh") == 0){

			if (strcmp(buf1, "the") == 0){
				strcpy(buf1, buf);
				continue;
			}
			//printf("(%d)%s\n", n, buf);

			fscanf(pFile, "%s", &buf);
			//printf("%s\n", buf);

			n = fscanf(pFile, "%u", &nVertices);
			//printf("nVertices:%u\n", nVertices);

			Vertices = (Vertex *)malloc(sizeof(Vertex) * nVertices);

			fscanf(pFile, "%*1s");

			for (int i = 0; i < nVertices; i++)
			{
				fscanf(pFile, "%f", &Vertices[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &Vertices[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &Vertices[i].z);
				//printf("%d %d %f %f %f\n", i, nVertices, Vertices[i].m_x, Vertices[i].m_y, Vertices[i].m_z);
				fscanf(pFile, "%*2s");
			}

			n = fscanf(pFile, "%u", &nIndices);
			//printf("nVertices:%u\n", nIndices);

			Indices = (Index *)malloc(sizeof(Index) * nIndices); 

			fscanf(pFile, "%*1s");
			for (int i = 0; i < nIndices; i++)
			{
				fscanf(pFile, "%*2s");
				fscanf(pFile, "%u", &Indices[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%u", &Indices[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%u", &Indices[i].z);
				//printf("%d %d %u %u %u\n", i, nIndices, Indices[i].m_ix, Indices[i].m_iy, Indices[i].m_iz);
				fscanf(pFile, "%*2s");
			}
		}


		if (strcmp(buf, "MeshTextureCoords") == 0){
			//printf("(%d)%s\n", n, buf);
			if (strcmp(buf1, "of") == 0){
				strcpy(buf1, buf);
				continue;
			}

			fscanf(pFile, "%s", &buf);
			//printf("%s\n", buf);

			n = fscanf(pFile, "%u", &nTextureCoords);
			//printf("nNormals:%u\n", nTextureCoords);

			fscanf(pFile, "%*1s");

			TextureCoords = (Texture *)malloc(sizeof(Texture) * nTextureCoords);

			for (int i = 0; i < nTextureCoords; i++)
			{
				fscanf(pFile, "%f", &TextureCoords[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &TextureCoords[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%*2s");
			}
		}
		strcpy( buf1, buf);
	}
	fclose(pFile);
}

void CreateNormals()
{
	Normals = (Normal*)malloc(sizeof(Normal) * nVertices);

	for (int i = 0; i < nIndices; i++)
	{
		vec3 ver0(Vertices[Indices[i].x].x, Vertices[Indices[i].x].y, Vertices[Indices[i].x].z);
		vec3 ver1(Vertices[Indices[i].y].x, Vertices[Indices[i].y].y, Vertices[Indices[i].y].z);
		vec3 ver2(Vertices[Indices[i].z].x, Vertices[Indices[i].z].y, Vertices[Indices[i].z].z);
		vec3 vec01 = ver1 - ver0;
		vec3 vec02 = ver2 - ver0;
		vec3 n = cross(vec01, vec02);
		n = normalize(n);

		Normals[Indices[i].x].x = n.x; Normals[Indices[i].x].y = n.y; Normals[Indices[i].x].z = n.z;
		Normals[Indices[i].y] = Normals[Indices[i].x];
		Normals[Indices[i].z] = Normals[Indices[i].x];
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


	glLineWidth(100);
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

	

		if (keyUp == 1)
		{
			rotate_x++;
			if (rotate_x >= 45)
			{
				rotate_x = 45;
			}
		}
		if (keyUp == 0)
		{
			rotate_x--;
			if (rotate_x <= 0)
			{
				rotate_x = 0;
			}
		}
		
		glRotatef(rotate_x, 1, 0, 0);


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
			TextureCoords);
		
		// 頂点データをセット
		glVertexPointer(
			3,
			GL_FLOAT,
			0,
			Vertices);
		
		// 法線データをセット
		glNormalPointer(
			GL_FLOAT,
			0,
			Normals);

		// インデックスデータをセット
		glDrawElements(
			GL_TRIANGLES,
			nIndices * 3,
			GL_UNSIGNED_INT,
			Indices);

		
	}
	glPopMatrix();
	
	glFlush();
}

void timer(int value) 
{
	glutTimerFunc(
		1000 / 60,// unsigned int millis
		timer,	// void (GLUTCALLBACK *func)(int value)
		0);		// int value
	glutPostRedisplay();


}

int main(int argc, char *argv[])
{

	LoadXFile();

	LoadTextureFile();

	CreateNormals();

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

	free (TextureCoords);
	free (Normals);
	free (Indices);
	free (Vertices);
}