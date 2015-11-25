
#ifndef TYPES_H_
#define TYPES_H_

// ���_�z��̍\����
typedef struct
{
	float x, y, z;
}Vertex;


// �C���f�b�N�X�z��̍\����
typedef struct
{
	unsigned int x, y, z;
}Index;


typedef struct
{
	unsigned char red, green, blue;
}TextureRGB;


// �@���z��̍\����
typedef struct
{
	float x, y, z;
}Normal;


// �e�N�X�`���z��̍\����
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

