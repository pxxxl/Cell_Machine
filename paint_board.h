#pragma once

#include <vector>
#include "paint_tools.h"
#define FACT_POSITION_X(x) (x*2-2)
#define FACT_POSITION_Y(y) (y*2+6)

using namespace std;


class paint_board
{
public:
	static void paint(const vector<int>);
	static void paint_ini();
	static void clearup();
};

