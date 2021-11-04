#pragma once
#define LENGTH 70
#define HEIGHT 30

using namespace std;

//�����Ա�������漰����Ԫ�ص�ȡ�ģ����������ΧΪ0 <= x <=��LENGTH-1��

class chess_board
{
	friend void paint();
	friend void clearup();
	friend void addtion();
	friend void initialize_array();
private:
	static bool board[HEIGHT][LENGTH];
	static bool board_co[HEIGHT][LENGTH];
public:
	static void change();
	static void live(int, int);
	static void dead(int, int);
	static void live_initialize(int, int);
	static void dead_initialize(int, int);
	static bool cell_state(int, int);
	chess_board();
};

