#include <iostream>
#include "paint_addition.h"
#include "paint_tools.h"

using namespace std;

void paint_addition::paint_console_menu() {
	gotoxy(CONSOLE_START_X, CONSOLE_START_Y);
	cout << "生命游戏  >控制台<";
	gotoxy(CONSOLE_POSITION1_X, CONSOLE_POSITION1_Y);
	cout << "开始运行";
	gotoxy(CONSOLE_POSITION2_X, CONSOLE_POSITION2_Y);
	cout << "放置细胞";	
	gotoxy(CONSOLE_POSITION3_X, CONSOLE_POSITION3_Y);
	cout << "速度设置";	
	gotoxy(CONSOLE_POSITION4_X, CONSOLE_POSITION4_Y);
	cout << "导入模板";
	gotoxy(CONSOLE_RETURN_X, CONSOLE_RETURN_Y);
	cout << "";
}