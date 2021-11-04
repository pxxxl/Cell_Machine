#include <Windows.h>
#include "paint_tools.h"

void gotoxy(int x, int y) {
	COORD pos{ x, y };
	HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOUT, pos);
}