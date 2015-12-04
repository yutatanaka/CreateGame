
#include "glut.h"
#include "KeyBoard.h"

bool KeyBoard::keyUp = false;
bool KeyBoard::keyDown = false;
bool KeyBoard::keyLeft = false;
bool KeyBoard::keyRight = false;
bool KeyBoard::keySpace = false;
bool KeyBoard::lastSpaceKey = false;

// �L�[�������ꂽ���̊֐�
void KeyBoard::PushUpdate(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'w': // w�L�[
		keyUp = true; break;
	case 's': // s�L�[
		keyDown = true; break;
	case 'a': // a�L�[
		keyLeft = true; break;
	case 'd': // d�L�[
		keyRight = true; break;
	case ' ': // space�L�[
		keySpace = true; break;
	}
}

// �L�[�������ꂽ���̊֐�
void KeyBoard::ReleaseUpdate(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': // w�L�[
		keyUp = false;    break;
	case 's': // s�L�[
		keyDown = false;  break;
	case 'a': // a�L�[
		keyLeft = false;  break;
	case 'd': // d�L�[
		keyRight = false; break;
	case ' ': // space�L�[
		keySpace = false; break;
	}
}