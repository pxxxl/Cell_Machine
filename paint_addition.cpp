#include <iostream>
#include "paint_addition.h"
#include "paint_tools.h"

using namespace std;

void paint_addition::paint_console_menu() {
	gotoxy(CONSOLE_START_X, CONSOLE_START_Y);
	cout << "������Ϸ  >����̨<";
	gotoxy(CONSOLE_POSITION1_X, CONSOLE_POSITION1_Y);
	cout << "��ʼ����";
	gotoxy(CONSOLE_POSITION2_X, CONSOLE_POSITION2_Y);
	cout << "����ϸ��";	
	gotoxy(CONSOLE_POSITION3_X, CONSOLE_POSITION3_Y);
	cout << "�ٶ�����";	
	gotoxy(CONSOLE_POSITION4_X, CONSOLE_POSITION4_Y);
	cout << "����ģ��";
	gotoxy(CONSOLE_RETURN_X, CONSOLE_RETURN_Y);
	cout << "";
}