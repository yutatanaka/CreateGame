
#ifndef TYPES_H_
#define TYPES_H_

// 頂点配列の構造体
typedef struct
{
	float x, y, z;
}Vertex;


// インデックス配列の構造体
typedef struct
{
	unsigned int x, y, z;
}Index;


typedef struct
{
	unsigned char red, green, blue;
}TextureRGB;


// 法線配列の構造体
typedef struct
{
	float x, y, z;
}Normal;


// テクスチャ配列の構造体
typedef struct
{
	float x, y;
}Texture;


Vertex *Vertices;

Index *Indices;

TextureRGB *pixels;
BITMAPFILEHEADER bitMapFile;
BITMAPINFOHEADER bitMapInfo;

Normal *Normals;

Texture *TextureCoords;

#endif  // TYPES_H_

