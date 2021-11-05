
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
	"��ʼ�ݻ�", "�༭ϸ��", "�����ٶ�", "����ģ��",
	"", "", "", "" };
const vector<string> paint_addition::formwork10 = {
	"ģ��1", "ģ��2", "ģ��3", "ģ��4",
	"", "", "", "" };
const vector<string> paint_addition::running11 = {
	"��������", "", "", "",
	"��x����ͣ", "", "", "" }; 
const vector<string> paint_addition::speed12 = {
	"ģ��1", "ģ��2", "ģ��3", "ģ��4",
	"", "", "", "" }; 
const vector<string> paint_addition::editcell13 = {
	"���ո����ϸ��״̬", "", "", "",
	"windows�û����������", "", "", "" };
void paint_addition::paint_console(vector<string> formwork) {
	gotoxy(CONSOLE_START_X, CONSOLE_START_Y);
	cout << ">������Ϸ<";
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