/*
  <23.10.23. 퀴즈>
  주차관리 시스템을 만든다고 가정했을 때 차에 대한 클래스를 만들어 구현하고
  주차등록과 주차요금을 계산하는 함수를 c++ / 파이썬 중 하나로 작성하시오.

  - Car Class는 차량번호, 배차시간, 출차시간, 배차 위치, 장애인차량 유무의 속성을 가지고 있습니다.
  - 주차 요금은 1시간당 2000원 30분에 1000원이며 10분 단위 계산 시  400원입니다. (10분미만 또한 400원)
*/

#include <iostream>
#include <string>
#include "car.h"
using namespace std;

int main() {
	int car_num;

	cout << "주차장에 입장한 차 번호를 입력하세요: ";
	cin >> car_num;
	Car test_car(car_num);
	cout << "현재 차 번호는 " << test_car.get_Car_num() << "입니다." << endl;
	test_car.set_dispatch_time();
	cout << "입차시간: " << test_car.get_dispatch_time() << endl;

	int out_check;
	cout << "주차장에서 차가 나갔다면 0을 입력해주세요 >>";
	cin >> out_check;
	test_car.set_departure_time();
	cout << "출차시간: " << test_car.get_departure_time() << endl;

	cout << "주차 요금은 " << test_car.calculate_fee() << "입니다." << endl;
}
