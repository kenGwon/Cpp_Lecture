#include "cafe_menu.h"

void CafeMenu::set_menu() {
	string temp;
	int token_index;

	getline(cin, temp);

	token_index = temp.rfind(" ");

	this->menu_name = temp.substr(0, token_index);
	this->menu_price = temp.substr(token_index, size(temp) - 1);
}

void CafeMenu::print_menu() {
	cout << this->menu_name << this->menu_price << endl;
}

string CafeMenu::get_menu_name() {
	return this->menu_name;
}

string CafeMenu::get_menu_price() {
	return this->menu_price;
}

int CafeMenu::get_int_menu_price() {
	return (int)(stod(this->menu_price) * 1000);
}
