#include "chess_board.h"
#include "paint_tools.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <vector>

bool chess_board::board[HEIGHT][LENGTH] = {0};
vector<int> chess_board::changed_cells = {};

using namespace std;

void chess_board::change() {
	chess_board::changed_cells.clear();
	int py[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (int x = 0; x != LENGTH; x++) {
		for (int y = 0; y != HEIGHT; y++) {
			int counter = 0;
			for (int i = 0; i < 8; i++) {
				int xi = x + py[i][0];
				int yi = y + py[i][1];
				if (xi < 0 || xi >= LENGTH || yi < 0 || yi >= HEIGHT) {}
				else {
					if (chess_board::cell_state(xi, yi)) {
						counter++;
					}
				}
			}
			if (counter == 3 && (!chess_board::cell_state(x, y))) {
				chess_board::changed_cells.push_back(y*100+x);
			}
			else if (counter != 2 && counter != 3 && chess_board::cell_state(x, y)) {
				chess_board::changed_cells.push_back(y*100+x);
			}
			else {
				//细胞状态不改变
			}
		}
	}
	if (!(chess_board::changed_cells.empty())) {
		auto begin_1 = chess_board::changed_cells.begin();
		auto end_1 = chess_board::changed_cells.end();
		while (begin_1 != end_1) {
			int change_position[2];
			change_position[0] = (*begin_1) % 100;
			change_position[1] = (*begin_1) / 100;
			chess_board::change_state(change_position[0], change_position[1]);
			begin_1++;
		}
	}
	return;
}
bool chess_board::cell_state(int x, int y) {
	if (x < 0 || x >= LENGTH || y < 0 || y >= HEIGHT) {
		cout << "错误！数组访问下标：chess_board!" << endl;
		_getch();
		exit(0);
	}
	return chess_board::board[y][x];
}
void chess_board::change_state(int x, int y) {
	if (chess_board::board[y][x]) {
		chess_board::board[y][x] = false;
	}
	else {
		chess_board::board[y][x] = true;
	}
	return;
}
int chess_board::return_HEIGHT() {
	return HEIGHT;
}
int chess_board::return_LENGTH() {
	return LENGTH;
}
vector<int> chess_board::return_change() {
	return chess_board::changed_cells;
}
