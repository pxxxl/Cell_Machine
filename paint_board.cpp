#include<stdlib.h>
#include<iostream>
#include "paint_board.h"
#include "chess_board.h"
#include "paint_tools.h"

#define FACT_POSITION_X(x) (x*2)
#define FACT_POSITION_Y(y) (y*2+6)

using namespace std;

void paint_board::clearup() {
	system("cls");
}

void paint_board::paint(const vector<int> changed_cell) {
	auto begin_1 = changed_cell.begin();
	auto end_1   = changed_cell.end();
	while (begin_1 != end_1) {
		int x = (*begin_1)%100;
		int y = (*begin_1)/100;
		gotoxy(FACT_POSITION_X(x), FACT_POSITION_Y(y));
		if (chess_board::cell_state(x, y)){
			cout << "¡ð";
		}
		else {
			cout << "¡ñ";
		}
		begin_1++;
	}
}

void paint_board::paint_ini() {
	gotoxy(FACT_POSITION_X(0), FACT_POSITION_Y(0));
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < LENGTH; j++) {
			cout << "¡ð";
		}
		cout << "\n";
	}
	gotoxy(0, 0);
}
