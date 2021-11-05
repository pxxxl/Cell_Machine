#pragma once
#include <string>
#include <vector>

//控制台将占用6行，第七行将开始绘制细胞盘

#define CONSOLE_HEIGHT      6
#define CONSOLE_START_X     2
#define CONSOLE_START_Y     0
#define CONSOLE_POSITION_X(position) ((position-1)%4*15 + 4)
#define CONSOLE_POSITION_Y(position) ((position-1)/4 +3)

#define CONSOLE_WARNING_X   0
#define CONSOLE_WARNING_Y   6

using namespace std;

class paint_addition
{
public:
	static const vector<string> menu9;
	static const vector<string> defau0;
	static const vector<string> formwork10;
	static const vector<string> running11;
	static const vector<string> speed12;
	static const vector<string> editcell13;

	static void paint_console(vector<string>);
	static void paint_warning(string);
	static void paint_cursor(int);
	static void clear_cursor(int);
	static void clear_console();
	static void console_uppage();
	static void console_downpage();
};