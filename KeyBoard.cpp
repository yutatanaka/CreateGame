
#include "glut.h"
#include "KeyBoard.h"

bool KeyBoard::keyUp = false;
bool KeyBoard::keyDown = false;
bool KeyBoard::keyLeft = false;
bool KeyBoard::keyRight = false;
bool KeyBoard::keySpace = false;
bool KeyBoard::lastSpaceKey = false;

// キーが押された時の関数
void KeyBoard::PushUpdate(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'w': // wキー
		keyUp = true; break;
	case 's': // sキー
		keyDown = true; break;
	case 'a': // aキー
		keyLeft = true; break;
	case 'd': // dキー
		keyRight = true; break;
	case ' ': // spaceキー
		keySpace = true; break;
	}
}

// キーが離された時の関数
void KeyBoard::ReleaseUpdate(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w': // wキー
		keyUp = false;    break;
	case 's': // sキー
		keyDown = false;  break;
	case 'a': // aキー
		keyLeft = false;  break;
	case 'd': // dキー
		keyRight = false; break;
	case ' ': // spaceキー
		keySpace = false; break;
	}
}