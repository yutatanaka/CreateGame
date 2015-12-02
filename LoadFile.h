
#ifndef _LOADFILE_H_
#define _LOADFILE_H_

#include <Windows.h>
#include "Types.h"

class LoadFile
{
public:

	// コンストラクタ
	LoadFile(char *fileData, char*textureFiledata);

	// デストラクタ
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

	// Ｘファイル読み込みメソッド
	void LoadXFile(char *fileData);

	// テクスチャファイル読み込みメソッド
	void LoadTextureFile(char *textureFileData);

	// Xファイルを読み込んだ後に法線を求めるメソッド
	void CreateNormals();
};

#endif // _LOADFILE_H_