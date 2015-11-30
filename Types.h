
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

extern Vertex *vertices;

extern Index *indices;

extern TextureRGB *pixels;
extern BITMAPFILEHEADER bitMapFile;
extern BITMAPINFOHEADER bitMapInfo;

extern Normal *normals;

extern Texture *textureCoords;

#endif  // TYPES_H_

