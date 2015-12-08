
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

class KeyBoard
{
public:

	// キーが押された時の処理メソッド
	static void PushUpdate(unsigned char key, int x, int y);
	
	// キーが離された時の処理メソッド
	static void ReleaseUpdate(unsigned char key, int x, int y);

	// キーボード変数
	static bool keyUp;
	static bool keyDown;
	static bool keyLeft;
	static bool keyRight;
	static bool keySpace;
	static bool lastSpaceKey;
};

#endif // _KEYBOARD_H_