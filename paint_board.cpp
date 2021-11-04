#include<stdlib.h>
#include<iostream>
#include "paint_board.h"
#include "chess_board.h"
#include "paint_tools.h"

using namespace std;

void paint_board::clearup() {
	system("cls");
}

void paint_board::paint() {
	gotoxy(START_PAINT_X, START_PAINT_Y);
	for (int x = 0; x < HEIGHT; x++) {
		for (int y = 0; y < LENGTH; y++) {
			if (chess_board::cell_state(x, y)) {
				cout << "¡ñ";
			}
			else {
				cout << "¡ð";
			}
		}
		cout << endl;
	}
}
