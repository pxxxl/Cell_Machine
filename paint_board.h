#pragma once

#include <vector>
#define FACT_POSITION_X(x) (x*2)
#define FACT_POSITION_Y(y) (y*2+6)

using namespace std;


class paint_board
{
public:
	static void paint(const vector<int>);
	static void paint_ini();
	static void clearup();
	static void paint_swap(int, int);
	static void move_cursor_on_board(int, int);
	static void up_left_cursor();
};

