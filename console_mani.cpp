#include "console_mani.h"
#include "paint_board.h"
#include "paint_addition.h"
#include "chess_board.h"
#include "data.h"

#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_LEFT    75
#define KEY_RIGHT   77
#define KEY_SPACE   32
#define KEY_X       120

#define MENU        9
#define FORMWORK    10
#define RUNNING     11
#define SPEED       12
#define EDITCELL    13
#define EDITFORM    14

#define SPEED_SLOW  1000
#define SPEED_MID   500
#define SPEED_FAST  250
#define SPEED_CRASY 100

using namespace std;


int console_mani::position       = 1;
int console_mani::situation      = 9;
int console_mani::editcell_x     = 0;
int console_mani::editcell_y     = 0;
int console_mani::speed_of_round = SPEED_MID;
bool console_mani::run_stop      = false;

void console_mani::console_main() {
	char     input = 0;
	paint_addition::paint_console(data::menu9);
	paint_board::paint_ini();
	paint_addition::paint_cursor(console_mani::position);
	while (1) {
			input_reaction(input = _getch());
	}
}
void console_mani::input_reaction(char input) {
	if (console_mani::situation == EDITCELL|| console_mani::situation == EDITFORM) {
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
			paint_addition::paint_console(data::running11);
			console_mani::run_stop = true;
			thread cellrun(console_mani::start_running);
			cellrun.detach(); }
			break;
		case 2:
			console_mani::situation = EDITCELL;
			paint_addition::clear_console();
			paint_addition::paint_console(data::editcell13);
			paint_board::move_cursor_on_board(console_mani::editcell_x, console_mani::editcell_y);
			break;
		case 3:
			console_mani::situation = SPEED;
			console_mani::position  = 1;
			paint_addition::clear_console();
			paint_addition::paint_console(data::speed12);
			paint_addition::paint_cursor(1);
			break;
		case 4:
			console_mani::situation = FORMWORK;
			console_mani::position = 1;
			paint_addition::clear_console();
			paint_addition::paint_console(data::formwork10);
			break;
		default:
			break;
		}
		break;
	case EDITCELL:
		paint_board::paint_swap(console_mani::editcell_x, console_mani::editcell_y);
		chess_board::change_state(console_mani::editcell_x, console_mani::editcell_y);
		break;
	case SPEED:
		switch (console_mani::position) {
		case 1:
			console_mani::speed_of_round = SPEED_SLOW;
			break;
		case 2:
			console_mani::speed_of_round = SPEED_MID;
			break;
		case 3:
			console_mani::speed_of_round = SPEED_FAST;
			break;
		case 4:
			console_mani::speed_of_round = SPEED_CRASY;
			break;
		default:
			break;
		}
		console_mani::x_pressed();
		break;
	case FORMWORK:
		console_mani::situation = EDITFORM;
		paint_addition::clear_console();
		paint_addition::paint_console(data::editform14);
		paint_board::move_cursor_on_board(console_mani::editcell_x, console_mani::editcell_y);
		break;
	case EDITFORM:
		paint_board::paint_formwork(data::choose_form(position), console_mani::editcell_x, console_mani::editcell_y);
		console_mani::x_pressed();
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
		paint_addition::paint_console(data::menu9);
		paint_addition::paint_cursor(console_mani::position);
		console_mani::run_stop = false;
		break;
	case EDITCELL:
		console_mani::situation = MENU;
		paint_addition::clear_console();
		paint_addition::paint_console(data::menu9);
		paint_addition::paint_cursor(console_mani::position);
		break;
	case SPEED:
		console_mani::situation = MENU;
		console_mani::position  = 1;
		paint_addition::clear_console();
		paint_addition::paint_console(data::menu9);
		paint_addition::paint_cursor(console_mani::position);
		break;
	case FORMWORK:
		console_mani::situation = MENU;
		console_mani::position = 1;
		paint_addition::clear_console();
		paint_addition::paint_console(data::menu9);
		paint_addition::paint_cursor(console_mani::position);
		break;
	case EDITFORM:
		console_mani::situation = MENU;
		console_mani::position = 1;
		paint_addition::clear_console();
		paint_addition::paint_console(data::menu9);
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
			std::this_thread::sleep_for(std::chrono::milliseconds(speed_of_round));
			paint_board::paint(chess_board::return_change());
			chess_board::change();
		}
		else {
			return;
		}
	}

	
}