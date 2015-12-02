
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

	static void DownUpdate(unsigned char key, int x, int y);

	static void UpUpdate(unsigned char key, int x, int y);
};

#endif // _KEYBOARD_H_