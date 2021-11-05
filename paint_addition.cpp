
#include <string>
#include <vector>
#include <iostream>
#include "chess_board.h"
#include "paint_tools.h"
#include "paint_addition.h"

using namespace std;

const vector<string> paint_addition::defau0 = {
	"        ", "        ", "        ", "        ",
	"        ", "        ", "        ", "        " };
const vector<string> paint_addition::menu9 = {
	"开始演化", "编辑细胞", "调整速度", "导入模板",
	"", "", "", "" };
const vector<string> paint_addition::formwork10 = {
	"模板1", "模板2", "模板3", "模板4",
	"", "", "", "" };
const vector<string> paint_addition::running11 = {
	"正在运行", "", "", "",
	"按x键暂停", "", "", "" }; 
const vector<string> paint_addition::speed12 = {
	"模板1", "模板2", "模板3", "模板4",
	"", "", "", "" }; 
const vector<string> paint_addition::editcell13 = {
	"按空格更改细胞状态", "", "", "",
	"windows用户可以鼠标点击", "", "", "" };
void paint_addition::paint_console(vector<string> formwork) {
	gotoxy(CONSOLE_START_X, CONSOLE_START_Y);
	cout << ">生命游戏<";
	for (int i = 1; i <= 8; i++) {
		gotoxy(CONSOLE_POSITION_X(i), CONSOLE_POSITION_Y(i));
		cout << formwork[i - 1];
	}
}
void paint_addition::paint_warning(string warning) {
	gotoxy(CONSOLE_WARNING_X, CONSOLE_WARNING_Y);
	cout << warning;
}
void paint_addition::paint_cursor(int position) {
	if (position <= 0 || position > 8) {
		return;
	}
	else {
		gotoxy(CONSOLE_POSITION_X(position)-2, CONSOLE_POSITION_Y(position));
		cout << "->";
	}
}
void paint_addition::clear_cursor(int position) {
	if (position <= 0 || position > 8) {
		return;
	}
	else {
		gotoxy(CONSOLE_POSITION_X(position) - 2, CONSOLE_POSITION_Y(position));
		cout << "  ";
	}
}
void paint_addition::clear_console() {
	for (int i = 1; i < 6; i++) {
		gotoxy(0, i);
		cout << "                                                           ";
	}
}
void paint_addition::console_downpage() {

}
void paint_addition::console_uppage() {

}