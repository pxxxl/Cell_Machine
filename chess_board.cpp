#include "chess_board.h"
#include "paint_tools.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

bool chess_board::board[HEIGHT][LENGTH] = {0};
vector<int> changed_cells = {};

using namespace std;

chess_board::chess_board(){};

void chess_board::change() {
	changed_cells.clear();
	int py[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (int x = 0; x != HEIGHT; x++) {
		for (int y = 0; y != LENGTH; y++) {
			int counter = 0;
			for (int i = 0; i < 8; i++) {
				int xi = x + py[i][0];
				int yi = y + py[i][1];
				if (xi < 0 || xi >= HEIGHT || yi < 0 || yi >= LENGTH) {}
				else {
					if (chess_board::cell_state(xi, yi)) {
						counter++;
					}
				}
			}
			if (counter == 3 && (!chess_board::cell_state(x, y))) {
				changed_cells.push_back(y*100+x);
			}
			else if (counter != 2 && counter != 3 && chess_board::cell_state(x, y)) {
				changed_cells.push_back(y*100+x);
			}
			else {
				//细胞状态不改变
			}
		}
	}
	auto begin_1 = changed_cells.begin();
	auto end_1   = changed_cells.end();
	while (begin_1 != end_1) {
		int change_position[2];
		change_position[0] = (*begin_1)%100;
		change_position[1] = (*begin_1)/100;
		chess_board::change_state(change_position[0], change_position[1]);
		begin_1++;
	}
	return;
}

void chess_board::live_initialize(int x, int y) {
	chess_board::board[x][y] = true;
}

void chess_board::dead_initialize(int x, int y) {
	chess_board::board[x][y] = false;
}

bool chess_board::cell_state(int x, int y) {
	if (x < 0 || x >= HEIGHT || y < 0 || y >= LENGTH) {
		cout << "错误！数组访问下标：chess_board!" << endl;
		_getch();
		exit(0);
	}
	return chess_board::board[x][y];
}

void chess_board::change_state(int x, int y) {
	if (chess_board::board[x][y]) {
		chess_board::board[x][y] = false;
	}
	else {
		chess_board::board[x][y] = true;
	}
	return;
}

vector<int> chess_board::return_change() {
	return changed_cells;
}