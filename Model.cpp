
#include "Model.h"
#include "glut.h"
#include "LoadFile.h"
#include "Vec3.h"

// コンストラクタ 
Model::Model(LoadFile *fileData):
loadFile(fileData)
{
}

// デストラクタ
Model::~Model()
{
	delete loadFile;
}

void Model::Draw(Vec3 position, Vec3 rotation, Vec3 scale)
{
	// テクスチャデータをVARMに転送
	glTexImage2D(
		GL_TEXTURE_2D,			//GLenum target
		0,						//GLint level
		GL_RGB,					//GLint internalformat
		loadFile->bitMapInfo.biWidth, loadFile->bitMapInfo.biHeight,				//GLsizei width, height
		0,						//GLint border
		GL_RGB,					//GLenum format
		GL_UNSIGNED_BYTE,		//GLenum type
		loadFile->pixels);				//const GLvoid *pixels

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

	glPushMatrix();
	{
		glTranslatef(position.x, position.y, position.z);
		// X軸回転
		glRotatef(rotation.x, 1, 0, 0);

		// Y軸回転
		glRotatef(rotation.y, 0, 1, 0);

		// Z軸回転
		glRotatef(rotation.z, 0, 0, 1);

		// 倍率
		glScalef(scale.x, scale.y, scale.z);


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
			loadFile->textureCoords);

		// 頂点データをセット
		glVertexPointer(
			3,
			GL_FLOAT,
			0,
			loadFile->vertices);

		// 法線データをセット
		glNormalPointer(
			GL_FLOAT,
			0,
			loadFile->normals);

		// インデックスデータをセット
		glDrawElements(
			GL_TRIANGLES,
			loadFile->nIndices * 3,
			GL_UNSIGNED_INT,
			loadFile->indices);
	}
	glPopMatrix();
}