#include "cafe.h"

void Cafe::get_cafe_menu() {
	for (int i = 0; i < menu_num; i++) {
		pArray[i].set_menu();
		total_order[pArray[i].get_menu_name()] = 0;
	}
}

void Cafe::print_cafe_menu() {

	cout << "========== CAFE MENU 리스트 ==========" << endl;

	for (int i = 0; i < menu_num; i++) {
		cout << "[ " << i + 1 << " ] ";
		pArray[i].print_menu();
	}
}

void Cafe::get_order() {

	string order;
	int present = 0;
	int count = 0;
	int order_num = 0;
	int invalid_order_num = 0;
	int one_order_price = 0;
	bool valid_flag = true;

	while (true) {
		cout << ">> ";
		getline(cin, order);

		// 0이 입력되면 주문입력 반복을 종료함
		if (order == "0") {
			break;
		}

		// 내가 구현한 아래의 로직이 예외없이 돌아가기 위해서는 주문 입력 스트링 끝에 반드시 공백 하나가 들어가 있어야함
		if (order.at(size(order) - 1) != ' ') {
			order.append(" ");
		}

		// 변수 초기화 후 잘못된 주문이 있는지 while문 돌면서 check
		present = 0;
		count = 0;
		while (order.find(" ", present) != -1) {
			order_num = stoi(order.substr(present, order.find(" ", present) - present)); // 주문 스트링을 토크나이징하여 int로 변환
			if (order_num > menu_num) {
				valid_flag = false;
				invalid_order_num = order_num;
				break;
			}
			count++; // 주문의 갯수
			present = order.find(" ", present) + 1; // 다음 루프를 위해 present값 갱신
		}

		// 잘못된 주문이 있었다면, 다음 주문을 받는 루프로 continue
		if (valid_flag == false) {
			cout << invalid_order_num << "는 없는 메뉴입니다..." << endl;
			valid_flag = true;
			continue;
		}

		// 모든 주문이 valid한 경우
		cout << "주문한 상품 : " << endl;

		// 변수 초기화 후 while문 둘면서 주문내역 출력하고, 주문수량 map자료형에 기억
		present = 0;
		one_order_price = 0;
		while (order.find(" ", present) != -1) {
			order_num = stoi(order.substr(present, order.find(" ", present) - present)); // 주문 스트링을 토크나이징하여 int로 변환
			order_num -= 1;

			total_order[pArray[order_num].get_menu_name()] += 1; // 주문 갯수 증가

			cout << pArray[order_num].get_menu_name() << " " << pArray[order_num].get_int_menu_price() << "원" << endl;

			one_order_price += pArray[order_num].get_int_menu_price();
			present = order.find(" ", present) + 1; // 다음 루프를 위해 present값 갱신
		}

		cout << "합계 : " << one_order_price << "원" << endl;
		total_sales += one_order_price;
	}
}

void Cafe::print_sales() {

	cout << "========== 매출 통계 ==========" << endl;

	for (int i = 0; i < menu_num; i++) {
		// 주문이 하나도 안들어온 메뉴는 continue로 출력하지 않고 넘김
		if (total_order[pArray[i].get_menu_name()] == 0) {
			continue;
		}

		cout << pArray[i].get_menu_name() << " " << total_order[pArray[i].get_menu_name()] << "개" << endl;
	}

	cout << "매출액 총계 : " << total_sales << "원" << endl;
}

