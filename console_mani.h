#pragma once

#include <conio.h>

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_X     120

#define MENU      9

class console_mani
{
public:
	static void console_main();           //主线程运行函数，以下都是辅助函数
	static int input_reaction(char, int, int); 
	static void space_pressed(int, int);
	static void x_pressed(int, int);
};

