#include "chess_board.h"
#include <iostream>
#include<stdlib.h>
#include<conio.h>

int chess_board::judger = 1;
bool chess_board::board[LENGTH][LENGTH] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
bool chess_board::board_co[LENGTH][LENGTH] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

chess_board::chess_board(){};

void chess_board::change() {
	int py[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (int x = 0; x != LENGTH; x++) {
		for (int y = 0; y != LENGTH; y++) {
			int counter = 0;
			for (int i = 0; i < 8; i++) {
				int xi = x + py[i][0];
				int yi = y + py[i][1];
				if (xi < 0 || xi >= LENGTH || yi < 0 || yi >= LENGTH) {}
				else {
					if (cell_state(xi, yi)) {
						counter++;
					}
				}
			}
			if (counter == 2) {

			}
			else {
				if (counter == 3) {
					chess_board::live(x, y);
				}
				else {
					chess_board::dead(x, y);
				}
			}
		}
	}
	for (int i = 0; i != LENGTH; i++) {
		for (int j = 0; j != LENGTH; j++) {
			chess_board::board[i][j] = chess_board::board_co[i][j];
		}
	}
	return;
}

void chess_board::live(int x, int y) {
	board_co[x][y] = true;
}

void chess_board::live_initialize(int x, int y) {
	board[x][y] = true;
}

void chess_board::dead(int x, int y) {
	board_co[x][y] = false;
}

void chess_board::dead_initialize(int x, int y) {
	board[x][y] = false;
}

bool chess_board::cell_state(int x, int y) {
	if (x < 0 || x >= LENGTH || y < 0 || y >= LENGTH) {
		cout << "错误！数组访问下标：chess_board!" << endl;
		_getch();
		exit(0);
	}
	return chess_board::board[x][y];
}