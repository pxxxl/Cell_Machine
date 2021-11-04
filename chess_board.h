#pragma once
#include <vector>
#define  LENGTH 70
#define  HEIGHT 30

using namespace std;
extern vector<int> changed_cells;
//本类成员函数中涉及数组元素调取的，传入参数范围为0 <= x <=（LENGTH-1）


class chess_board
{
	friend void paint();
	friend void clearup();
	friend void addtion();
	friend void initialize_array();
private:
	static bool board[HEIGHT][LENGTH];
public:
	static void change();
	//vector里放的是被改变细胞的坐标
	static void live_initialize(int, int);
	static void dead_initialize(int, int);
	static bool cell_state     (int, int);
	static void change_state   (int, int);
	static vector<int> return_change();
	chess_board();
};

