
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

class KeyBoard
{
public:

	// �L�[�������ꂽ���̏������\�b�h
	static void PushUpdate(unsigned char key, int x, int y);
	
	// �L�[�������ꂽ���̏������\�b�h
	static void ReleaseUpdate(unsigned char key, int x, int y);

	// �L�[�{�[�h�ϐ�
	static bool keyUp;
	static bool keyDown;
	static bool keyLeft;
	static bool keyRight;
	static bool keySpace;
	static bool lastSpaceKey;
};

#endif // _KEYBOARD_H_