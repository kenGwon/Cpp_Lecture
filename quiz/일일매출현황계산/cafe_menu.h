#pragma once
#ifndef _CAFE__MENU_H_
#define _CAFE__MENU_H_

#include <iostream>
#include <string>
using namespace std;

class CafeMenu {
private:
	string menu_name;
	string menu_price;

public:
	void set_menu();
	void print_menu();

	string get_menu_name();
	string get_menu_price();
	int get_int_menu_price();
};


#endif // !_CAFE__MENU_H_
