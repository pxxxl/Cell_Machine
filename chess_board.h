#pragma once
#include <vector>
#define  LENGTH 70
#define  HEIGHT 40

using namespace std;
extern vector<int> changed_cells;
//�����Ա�������漰����Ԫ�ص�ȡ�ģ����������ΧΪ0 <= x <=��LENGTH-1��


class chess_board
{
private:
	static bool board[HEIGHT][LENGTH];
	static vector<int> changed_cells;
public:
	static void change();
	//vector��ŵ��Ǳ��ı�ϸ��������
	static bool cell_state     (int, int);
	static void change_state   (int, int);
	static vector<int> return_change();
	static int return_LENGTH();
	static int return_HEIGHT();
};

