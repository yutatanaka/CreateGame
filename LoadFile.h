
#ifndef _LOADFILE_H_
#define _LOADFILE_H_

class LoadFile
{
public:

	// �R���X�g���N�^
	LoadFile();

	// �f�X�g���N�^
	~LoadFile();

public:
	// �w�t�@�C���ǂݍ��݃��\�b�h
	void LoadXFile(char *fileData);

	// �e�N�X�`���t�@�C���ǂݍ��݃��\�b�h
	void LoadTextureFile(char *fileData);
};

extern LoadFile loadFile;



#endif // _LOADFILE_H_