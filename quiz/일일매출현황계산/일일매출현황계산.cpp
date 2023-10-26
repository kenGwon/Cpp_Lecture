/*
  <23.10.24. 퀴즈>
  cafe_menu 클래스를 이용하여 제품을 나타내고
  cafe 클래스는 그것을 이용해서 제품 데이터를 읽어들이고 출력한 후
  주문을 받아 주문 내역을 출력하고,
  주문이 끝나면 그날의 매출통계를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include "cafe.h"
#include "cafe_menu.h"
using namespace std;

int main()
{
	int menu_num;
	cin >> menu_num;
	cin.ignore();

	Cafe kenGwon_cafe(menu_num);

	kenGwon_cafe.get_cafe_menu();
	kenGwon_cafe.print_cafe_menu();

	kenGwon_cafe.get_order();
	kenGwon_cafe.print_sales();
}

