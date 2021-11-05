#include "console_mani.h"
#include "paint_board.h"
#include "paint_addition.h"
#include "chess_board.h"

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_X     120

#define MENU      9
#define FORMWORK  10
#define RUNNING   11
#define SPEED     12
#define EDITCELL  13

using namespace std;


int console_mani::position   = 1;
int console_mani::situation  = 9;
int console_mani::editcell_x = 0;
int console_mani::editcell_y = 0;
bool console_mani::run_stop  = false;

void console_mani::console_main() {
	char     input = 0;
	paint_addition::paint_console(paint_addition::menu9);
	paint_board::paint_ini();
	paint_addition::paint_cursor(console_mani::position);
	while (1) {
			input_reaction(input = _getch());
	}
}
void console_mani::input_reaction(char input) {
	if (console_mani::situation == EDITCELL) {
		console_mani::on_editcell_reaction(input);
	}
	else if (console_mani::situation == RUNNING) {
		console_mani::on_runtime_reaction(input);
	}
	else {
		console_mani::on_console_reaction(input);
	}
	return;
}
void console_mani::space_pressed() {
	switch (console_mani::situation) {
	case MENU:
		switch (console_mani::position) {
		case 1: {
			console_mani::situation = RUNNING;
			paint_addition::clear_console();
			paint_addition::paint_console(paint_addition::running11);
			console_mani::run_stop = true;
			//thread cellrun(console_mani::start_running);
			//cellrun.detach();
			console_mani::start_running();
			break; }
		case 2:
			console_mani::situation = EDITCELL;
			paint_addition::clear_console();
			paint_addition::paint_console(paint_addition::editcell13);
			paint_board::move_cursor_on_board(console_mani::editcell_x, console_mani::editcell_y);
			break;
		case 3:
			paint_addition::clear_console();
			paint_addition::paint_console(paint_addition::speed12);
			break;
		case 4:
			paint_addition::clear_console();
			paint_addition::paint_console(paint_addition::formwork10);
			break;
		default:
			break;
		}
		break;
	case EDITCELL:
		paint_board::paint_swap(console_mani::editcell_x, console_mani::editcell_y);
		chess_board::change_state(console_mani::editcell_x, console_mani::editcell_y);
		break;
	default:
		break;
	}
}
void console_mani::x_pressed() {
	switch (console_mani::situation) {
	case MENU:
		break;
	case RUNNING:
		console_mani::situation = MENU;
		paint_addition::clear_console();
		paint_addition::paint_console(paint_addition::menu9);
		paint_addition::paint_cursor(console_mani::position);
		console_mani::run_stop = false;
		break;
	case EDITCELL:
		console_mani::situation = MENU;
		paint_addition::clear_console();
		paint_addition::paint_console(paint_addition::menu9);
		paint_addition::paint_cursor(console_mani::position);
		break;
	default:
		break;
	}
}
void console_mani::on_console_reaction(char input) {
	switch (input) {
	case KEY_UP:
		paint_addition::clear_cursor(position);
		if (console_mani::position < 5) {
			console_mani::position += 4;
			paint_addition::paint_cursor(console_mani::position);
			paint_addition::console_uppage();
		}
		else {
			console_mani::position -= 4;
			paint_addition::paint_cursor(console_mani::position);
		}
		break;
	case KEY_DOWN:
		paint_addition::clear_cursor(position);
		if (console_mani::position < 5) {
			console_mani::position += 4;
			paint_addition::paint_cursor(console_mani::position);
		}
		else {
			console_mani::position -= 4;
			paint_addition::paint_cursor(console_mani::position);
			paint_addition::console_downpage();
		}
		break;
	case KEY_LEFT:
		if (console_mani::position != 1 && console_mani::position != 5) {
			paint_addition::clear_cursor(position);
			console_mani::position -= 1;
			paint_addition::paint_cursor(console_mani::position);
		}
		break;
	case KEY_RIGHT:
		if (console_mani::position != 4 && console_mani::position != 8) {
			paint_addition::clear_cursor(position);
			console_mani::position += 1;
			paint_addition::paint_cursor(console_mani::position);
		}
		break;
	case KEY_SPACE:
		console_mani::space_pressed();
		break;
	case KEY_X:
		console_mani::x_pressed();
		break;
	}
}
void console_mani::on_editcell_reaction(char input) {
	switch (input) {
	case KEY_UP:
		if (console_mani::editcell_y != -1) {
			console_mani::editcell_y--;
			paint_board::move_cursor_on_board(editcell_x, editcell_y);
		}
		break;
	case KEY_DOWN:
		if (console_mani::editcell_y != chess_board::return_HEIGHT()) {
			console_mani::editcell_y++;
			paint_board::move_cursor_on_board(editcell_x, editcell_y);
		}
		break;
	case KEY_LEFT:
		if (console_mani::editcell_x != -1) {
			console_mani::editcell_x--;
			paint_board::move_cursor_on_board(editcell_x, editcell_y);
		}
		break;
	case KEY_RIGHT:
		if (console_mani::editcell_x != chess_board::return_LENGTH()) {
			console_mani::editcell_x++;
			paint_board::move_cursor_on_board(editcell_x, editcell_y);
		}
		break;
	case KEY_SPACE:
		console_mani::space_pressed();
		break;
	case KEY_X:
		console_mani::x_pressed();
		break;
	}
}
void console_mani::on_runtime_reaction(char input) {
	switch (input) {
	case KEY_X:
		console_mani::x_pressed();
		break;
	default:
		break;
	}
}
void console_mani::start_running() {
	while (1) {
		if (console_mani::run_stop) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			chess_board::change();
			paint_board::paint(chess_board::return_change());
		}
		else {
			return;
		}
	}

	
}