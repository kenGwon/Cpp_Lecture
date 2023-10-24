#include "car.h"

Car::Car(int car_num) {
	this->car_num = car_num;
}

Car::~Car() { }

int Car::get_Car_num() {
	return this->car_num;
}

double Car::get_dispatch_time() {
	return this->dispatch_time;
}

double Car::get_departure_time() {
	return this->departure_time;
}

void Car::set_dispatch_time() {
	this->dispatch_time = time(NULL);
}

void Car::set_departure_time() {
	this->departure_time = time(NULL);
}

int Car::calculate_fee() {
	double time_diff;

	time_diff = difftime(this->departure_time, this->dispatch_time);

	time_diff /= 60; // 초단위 리턴값을 분단위로 환산

	int hour_fee, half_hour_fee, ten_minute_fee;

	hour_fee = (int)time_diff / 60;
	half_hour_fee = ((int)time_diff % 60) / 30;
	ten_minute_fee = (((int)time_diff % 60) % 30) / 10;

	if (time_diff < 10) {
		if (for_disabled) {
			return 0.5 * 400;
		}
		else {
			return 400;
		}
	}

	if ((((int)time_diff % 60) % 30) % 10 == 0) {
		if (for_disabled) {
			return 0.5 * (hour_fee * 2000 + half_hour_fee * 1000 + ten_minute_fee * 400);
		}
		else {
			return hour_fee * 2000 + half_hour_fee * 1000 + ten_minute_fee * 400;
		}
	}
	else {
		if (for_disabled) {
			return 0.5 * (hour_fee * 2000 + half_hour_fee * 1000 + ten_minute_fee * 400 + 400);
		}
		else {
			return hour_fee * 2000 + half_hour_fee * 1000 + ten_minute_fee * 400 + 400;
		}
	}
}
