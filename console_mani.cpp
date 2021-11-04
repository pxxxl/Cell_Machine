#include<Windows.h>
#include "console_mani.h"
#include "paint_board.h"
#include "paint_addition.h"

using namespace std;

void console_mani::console_main() {
	int f_position = 1;
	int position   = 1;
	int situation  = 9;
	char input     = 0;
	paint_addition::paint_console(paint_addition::menu9);
	paint_board::paint_ini();
	paint_addition::paint_cursor(position);
	while (1) {
		f_position = position;
		position = input_reaction(input = _getch(), position, situation);
		paint_addition::clear_cursor(f_position);
		paint_addition::paint_cursor(position);
	}
}

int console_mani::input_reaction(char input, int position, int situation) {
	switch (input) {
	case KEY_UP:
		if (position < 5) {
			position += 4;
			paint_addition::paint_cursor(position);
			paint_addition::console_uppage();
		}
		else {
			position -= 4;
			paint_addition::paint_cursor(position);
		}
		break;
	case KEY_DOWN:
		if (position < 5) {
			position += 4;
			paint_addition::paint_cursor(position);
		}
		else {
			position -= 4;
			paint_addition::paint_cursor(position);
			paint_addition::console_downpage();
		}
		break;
	case KEY_LEFT:
		if (position != 1 && position != 5) {
			position -= 1;
			paint_addition::paint_cursor(position);
		}
		break;
	case KEY_RIGHT:
		if (position != 4 && position != 8) {
			position += 1;
			paint_addition::paint_cursor(position);
		}
		break;
	case KEY_SPACE:
		console_mani::space_pressed(position, situation);
		break;
	case KEY_X:
		console_mani::x_pressed(position, situation);
		break;
	}
	return position;
}

void console_mani::space_pressed(int position, int situation) {
	switch (situation) {
	case MENU:
		switch (position) {
		case 1:
			break;
		case 2:

			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void console_mani::x_pressed(int position, int situation) {
	switch (situation) {
	case MENU:
		break;
	default:
		break;
	}
}
