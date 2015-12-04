
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

class KeyBoard
{
public:

	// キーボード変数
	static bool keyUp ;
	static bool keyDown ;
	static bool keyLeft ;
	static bool keyRight ;
	static bool keySpace ;
	static bool lastSpaceKey ;

	static void PushUpdate(unsigned char key, int x, int y);

	static void ReleaseUpdate(unsigned char key, int x, int y);
};

#endif // _KEYBOARD_H_