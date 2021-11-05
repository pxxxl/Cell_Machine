#pragma once

#include<vector>
#include<string>

using namespace std;

#ifndef XY_STRUCT
#define XY_STRUCT
struct xy {
	int x;
	int y;
};
#endif

class data
{
public:
	static const vector<string> menu9;
	static const vector<string> defau0;
	static const vector<string> formwork10;
	static const vector<string> running11;
	static const vector<string> speed12;
	static const vector<string> editcell13;
	static const vector<string> editform14;

	static const vector<xy> form1;
	static const vector<xy> form2;
	static const vector<xy> form3;
	static const vector<xy> form4;

	static vector<xy> choose_form(int);

};

