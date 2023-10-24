#pragma once
#ifndef _CAFE_H_
#define _CAFE_H_

#include <iostream>
#include <string>
#include <map>
#include "cafe_menu.h"
using namespace std;

class Cafe {
private:
	CafeMenu* pArray;
	int menu_num;
	int total_sales;
	map<string, int> total_order;

public:
	Cafe(int menu_num) {
		pArray = new CafeMenu[menu_num];
		this->menu_num = menu_num;
		this->total_sales = 0;
	}

	void get_cafe_menu();
	void print_cafe_menu();
	void get_order();
	void print_sales();
};
#endif // !_CAFE_H_#pragma once
