#include <Windows.h>
#include "paint_tools.h"

HANDLE hOUT = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) {
	COORD pos{ x, y };
	SetConsoleCursorPosition(hOUT, pos);
}

void set_console() {
	SetConsoleTitle(L"¿µÍşÉúÃüÓÎÏ·           ----EZÖÆ");
}
