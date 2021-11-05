#include "data.h"

const vector<string> data::defau0 = {
	"        ", "        ", "        ", "        ",
	"        ", "        ", "        ", "        " };
const vector<string> data::menu9 = {
	"开始演化", "编辑细胞", "调整速度", "导入模板",
	"", "", "", "" };
const vector<string> data::formwork10 = {
	"模板1", "模板2", "模板3", "模板4",
	"", "", "", "" };
const vector<string> data::running11 = {
	"正在运行", "", "", "",
	"按x键暂停", "", "", "" };
const vector<string> data::speed12 = {
	"慢速", "中速", "快速", "超快速",
	"", "", "", "" };
const vector<string> data::editcell13 = {
	"按空格更改细胞状态，按x返回", "", "", "",
	"windows用户可以鼠标点击", "", "", "" };
const vector<string> data::editform14 = {
	"按空格放置模板，按x返回", "", "", "",
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
