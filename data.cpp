#include "data.h"

const vector<string> data::defau0 = {
	"        ", "        ", "        ", "        ",
	"        ", "        ", "        ", "        " };
const vector<string> data::menu9 = {
	"��ʼ�ݻ�", "�༭ϸ��", "�����ٶ�", "����ģ��",
	"", "", "", "" };
const vector<string> data::formwork10 = {
	"ģ��1", "ģ��2", "ģ��3", "ģ��4",
	"", "", "", "" };
const vector<string> data::running11 = {
	"��������", "", "", "",
	"��x����ͣ", "", "", "" };
const vector<string> data::speed12 = {
	"����", "����", "����", "������",
	"", "", "", "" };
const vector<string> data::editcell13 = {
	"���ո����ϸ��״̬����x����", "", "", "",
	"windows�û����������", "", "", "" };
const vector<string> data::editform14 = {
	"���ո����ģ�壬��x����", "", "", "",
	"", "", "", "" };

const vector<xy> data::form1 = {
{0,1}, {0,2}, {1,2}, {-1,2}, {0,3}, 
{0,-1}, {0,-2}, {1,-2}, {-1,-2}, {0,-3}, 
{2,0}, {3,1}, {3,0}, {3,-1}, {4,0}, 
{-2,0}, {-3,1}, {-3,0}, {-3,-1}, {-4,0},};
const vector<xy> data::form2 = {
	{0,-1}, {0,-2}, {1,-1}, {1,-2}, {-2,0},
{1,1}, {0,1}, {-1,1}, {1,2}, {0,2},
{-1,2} };
const vector<xy> data::form3 = { {1,1} };
const vector<xy> data::form4 = { {1,1} };

vector<xy> data::choose_form(int position) {
	vector<xy> form;
	switch (position) {
	case 1:
		form = data::form1;
		break;
	case 2:
		form = data::form2;
		break;
	case 3:
		form = data::form3;
		break;
	case 4:
		form = data::form4;
		break;
	default:
		break;
	}
	return form;
}
