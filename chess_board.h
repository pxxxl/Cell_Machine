#pragma once
#include <vector>
#define  LENGTH 70
#define  HEIGHT 30

using namespace std;
extern vector<int> changed_cells;
//�����Ա�������漰����Ԫ�ص�ȡ�ģ����������ΧΪ0 <= x <=��LENGTH-1��


class chess_board
{
	friend void paint();
	friend void clearup();
	friend void addtion();
	friend void initialize_array();
private:
	static bool board[HEIGHT][LENGTH];
public:
	static void change();
	//vector��ŵ��Ǳ��ı�ϸ��������
	static void live_initialize(int, int);
	static void dead_initialize(int, int);
	static bool cell_state     (int, int);
	static void change_state   (int, int);
	static vector<int> return_change();
	chess_board();
};

