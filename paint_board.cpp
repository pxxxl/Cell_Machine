#include "paint_board.h"
#include "chess_board.h"
#include "paint_tools.h"
#include "data.h"

#define FACT_POSITION_X(x) (x*2)
#define FACT_POSITION_Y(y) (y+6)

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
		//我为什么在这里放了！，因为调用change会自动改变细胞
		if (!chess_board::cell_state(x, y)){
			cout << "○";
		}
		else {
			cout << "●";
		}
		begin_1++;
	}
	paint_board::up_left_cursor();
}
void paint_board::paint_ini() {
	gotoxy(FACT_POSITION_X(0), FACT_POSITION_Y(0));
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < LENGTH; j++) {
			cout << "○";
		}
		cout << "\n";
	}
	paint_board::up_left_cursor();
}
void paint_board::paint_swap(int x, int y)
{
	if (!(x < 0 || x >= LENGTH || y < 0 || y >= HEIGHT)) {
		gotoxy(FACT_POSITION_X(x), FACT_POSITION_Y(y));
		if (chess_board::cell_state(x, y)) {
			cout << "○";
		}
		else {
			cout << "●";
		}
		gotoxy(FACT_POSITION_X(x), FACT_POSITION_Y(y));
	}
}
void paint_board::move_cursor_on_board(int x, int y) {
	gotoxy(FACT_POSITION_X(x), FACT_POSITION_Y(y));
}
void paint_board::up_left_cursor() {
	gotoxy(0, 0);
}
void paint_board::paint_formwork(vector<xy> form, int x1, int y1) {
	auto begin1 = form.begin();
	auto end1   = form.end();
	while (begin1 != end1) {
		paint_swap(x1 + (*begin1).x, y1 + (*begin1).y);
		chess_board::change_state(x1 + (*begin1).x, y1 + (*begin1).y);
		begin1++;
	}
}

