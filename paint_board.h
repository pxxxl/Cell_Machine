#pragma once

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#define FACT_POSITION_X(x) (x*2)
#define FACT_POSITION_Y(y) (y*2+6)

using namespace std;

#ifndef XY_STRUCT
#define XY_STRUCT
struct xy {
	int x;
	int y;
};
#endif




class paint_board
{
public:
	static void paint(const vector<int>);
	static void paint_ini();
	static void clearup();
	static void paint_swap(int, int);
	static void move_cursor_on_board(int, int);
	static void up_left_cursor();
	static void paint_formwork(vector<xy>,int,int);
};

