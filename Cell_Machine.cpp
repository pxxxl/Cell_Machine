// Cell_Machine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//控制台将占用前六行
//第七行空出
//第八行开始生命游戏□■

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "chess_board.h"
#include "paint_addition.h"
#include "paint_board.h"
#include "paint_addition.h"

using namespace std;

void initialize_cells();
void start_run();
void initialize_array();

int main()
{
	initialize_array();
	initialize_cells();
	paint_addition::paint_console_menu();
	start_run();
}

void initialize_cells() {
	cout << "请输入细胞坐标" << endl;
	while (true) {
		int x, y;
		cin >> x >> y;
		if (x <= 0 || x > LENGTH || y <= 0 || y > LENGTH) {
			break;
		}
		else {
			chess_board::live_initialize(x - 1, y - 1);
		}
	}
}

void start_run() {
	while (1) {
		paint_board::clearup();
		paint_board::paint();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		chess_board::change();
	}
}

void initialize_array() {
	memset(chess_board::board, 0, sizeof(chess_board::board));
	memset(chess_board::board_co, 0, sizeof(chess_board::board_co));
}






// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
