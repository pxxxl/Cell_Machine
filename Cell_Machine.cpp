//控制台将占用前六行
//第七行空出
//第八行开始生命游戏    □■●○

// 文件chess_board      负责所有更改细胞值的操作
// 文件console_mani     负责操作控制台(同时向paint_addition发指令)
// 文件paint_addition   负责绘制控制台
// 文件paint_board      负责绘制细胞图
// 文件paint_tools      负责掌管windows系统工具

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "chess_board.h"
#include "paint_addition.h"
#include "paint_board.h"
#include "paint_addition.h"
#include "console_mani.h"

using namespace std;
void start_console();

int main()
{
	start_console();
}


void start_console() {
	console_mani::console_main();
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
