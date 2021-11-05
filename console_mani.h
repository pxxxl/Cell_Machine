#pragma once

#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <algorithm>

class console_mani
{
private:
	static int position;
	static int situation;
	static int editcell_x;
	static int editcell_y;
	static int speed_of_round;
	static bool run_stop;

	static void input_reaction(char);
	static void space_pressed();
	static void x_pressed();
	static void on_editcell_reaction(char);
	static void on_console_reaction(char);
	static void on_runtime_reaction(char);
	static void start_running();

public:
	static void console_main();           
};

