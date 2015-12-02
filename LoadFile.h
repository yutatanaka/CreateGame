
#ifndef _LOADFILE_H_
#define _LOADFILE_H_

class LoadFile
{
public:

	// コンストラクタ
	LoadFile();

	// デストラクタ
	~LoadFile();

public:
	// Ｘファイル読み込みメソッド
	void LoadXFile(char *fileData);

	// テクスチャファイル読み込みメソッド
	void LoadTextureFile(char *fileData);

	// Xファイルを読み込んだ後に法線を求めるメソッド
	void CreateNormals();
};

extern LoadFile loadFile;



#endif // _LOADFILE_H_