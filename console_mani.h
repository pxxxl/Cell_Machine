#pragma once

#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <algorithm>

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_X     120

#define MENU      9
#define FORMWORK  10
#define RUNNING   11
#define SPEED     12
#define EDITCELL  13

class console_mani
{
private:
	static int position;
	static int situation;
	static int editcell_x;
	static int editcell_y;
	static bool run_stop;
public:
	static void console_main();           //主线程运行函数，以下都是辅助函数
	static void input_reaction(char); 
	static void space_pressed();
	static void x_pressed();
	static void on_editcell_reaction(char);
	static void on_console_reaction(char);
	static void on_runtime_reaction(char);
	static void start_running();
};

