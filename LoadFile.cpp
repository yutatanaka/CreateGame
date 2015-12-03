
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>
#include "glm\glm.hpp"
#include "Types.h"
#include "LoadFile.h"


// コンストラクタ
LoadFile::LoadFile(char *fileData, char *textureFileData)
{
	LoadXFile(fileData);
	LoadTextureFile(textureFileData);
	CreateNormals();
}

// デストラクタ
LoadFile::~LoadFile()
{
	free (vertices);
	free (indices);
	free (textureCoords);
	free (normals);
	free (pixels);
}

// Xファイルを読み込む関数
void LoadFile::LoadXFile(char *fileData)
{
	FILE *pFile = fopen(fileData, "r");
	assert(pFile != NULL);

	char buffer[256];
	char buffer1[256];
	int normal;


	while (1)
	{
		normal = fscanf(pFile, "%s", &buffer);
		if (normal < 1)
			break;
		if (strcmp(buffer, "template") == 0){
			while (strcmp(buffer, "}") != 0){
				normal = fscanf(pFile, "%s", &buffer);
			}
		}
		if (strcmp(buffer, "Mesh") == 0){

			if (strcmp(buffer1, "the") == 0){
				strcpy(buffer1, buffer);
				continue;
			}
			//printf("(%d)%s\n", n, buf);

			fscanf(pFile, "%s", &buffer);
			//printf("%s\n", buf);

			normal = fscanf(pFile, "%u", &nVertices);
			//printf("nVertices:%u\n", nVertices);

			fscanf(pFile, "%*1s");

			vertices = (Vertex *)malloc(sizeof(Vertex) * nVertices);

			for (int i = 0; i < nVertices; i++)
			{
				fscanf(pFile, "%f", &vertices[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &vertices[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &vertices[i].z);
				//printf("%d %d %f %f %f\n", i, nVertices, Vertices[i].m_x, Vertices[i].m_y, Vertices[i].m_z);
				fscanf(pFile, "%*2s");
			}

			normal = fscanf(pFile, "%u", &nIndices);
			//printf("nVertices:%u\n", nIndices);

			indices = (Index *)malloc(sizeof(Index) * nIndices);


			fscanf(pFile, "%*1s");
			for (int i = 0; i < nIndices; i++)
			{
				fscanf(pFile, "%*2s");
				fscanf(pFile, "%u", &indices[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%u", &indices[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%u", &indices[i].z);
				//printf("%d %d %u %u %u\n", i, nIndices, Indices[i].m_ix, Indices[i].m_iy, Indices[i].m_iz);
				fscanf(pFile, "%*2s");
			}
		}


		if (strcmp(buffer, "MeshTextureCoords") == 0){
			//printf("(%d)%s\n", n, buf);
			if (strcmp(buffer1, "of") == 0){
				strcpy(buffer1, buffer);
				continue;
			}

			fscanf(pFile, "%s", &buffer);
			//printf("%s\n", buf);

			normal = fscanf(pFile, "%u", &nTextureCoords);
			//printf("nNormals:%u\n", nTextureCoords);

			fscanf(pFile, "%*1s");

			textureCoords = (Texture *)malloc(sizeof(Texture) * nTextureCoords);

			for (int i = 0; i < nTextureCoords; i++)
			{
				fscanf(pFile, "%f", &textureCoords[i].x);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%f", &textureCoords[i].y);
				fscanf(pFile, "%*1s");
				fscanf(pFile, "%*2s");
			}
		}
		strcpy(buffer1, buffer);
	}
	fclose(pFile);
}

// テクスチャファイルを読み込む関数
void LoadFile::LoadTextureFile(char *fileData)
{
	FILE *pFile = fopen(fileData, "rb");
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

// Ｘファイルを読み込んだ後に法線を求めるメソッド
void LoadFile::CreateNormals()
{
	normals = (Normal*)malloc(sizeof(Normal) * nVertices);

	for (int i = 0; i < nIndices; i++)
	{
		glm::vec3 ver0(vertices[indices[i].x].x, vertices[indices[i].x].y, vertices[indices[i].x].z);
		glm::vec3 ver1(vertices[indices[i].y].x, vertices[indices[i].y].y, vertices[indices[i].y].z);
		glm::vec3 ver2(vertices[indices[i].z].x, vertices[indices[i].z].y, vertices[indices[i].z].z);
		glm::vec3 vec01 = ver1 - ver0;
		glm::vec3 vec02 = ver2 - ver0;
		glm::vec3 n = cross(vec01, vec02);
		n = normalize(n);

		normals[indices[i].x].x = n.x; normals[indices[i].x].y = n.y; normals[indices[i].x].z = n.z;
		normals[indices[i].y] = normals[indices[i].x];
		normals[indices[i].z] = normals[indices[i].x];
	}
}