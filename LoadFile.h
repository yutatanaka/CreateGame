
#ifndef _LOADFILE_H_
#define _LOADFILE_H_

#include <Windows.h>
#include "Types.h"

class LoadFile
{
public:

	// �R���X�g���N�^
	LoadFile(char *fileData, char*textureFiledata);

	// �f�X�g���N�^
	~LoadFile();

	unsigned int nVertices;
	unsigned int nIndices;
	unsigned int nNormals;
	unsigned int nTextureCoords;

	Vertex *vertices;

	Index *indices;

	TextureRGB *pixels;

	BITMAPFILEHEADER bitMapFile;
	BITMAPINFOHEADER bitMapInfo;

	Normal *normals;

	Texture *textureCoords;

private:

	// �w�t�@�C���ǂݍ��݃��\�b�h
	void LoadXFile(char *fileData);

	// �e�N�X�`���t�@�C���ǂݍ��݃��\�b�h
	void LoadTextureFile(char *textureFileData);

	// X�t�@�C����ǂݍ��񂾌�ɖ@�������߂郁�\�b�h
	void CreateNormals();
};

#endif // _LOADFILE_H_