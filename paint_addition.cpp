
#include "chess_board.h"
#include "paint_tools.h"
#include "paint_addition.h"

using namespace std;

void paint_addition::paint_console(vector<string> formwork) {
	gotoxy(CONSOLE_START_X, CONSOLE_START_Y);
	cout << "¿ØÖÆÌ¨";
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