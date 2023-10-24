#pragma once
#ifndef CAR_H
#define CAR_H

#include <ctime>

class Car {
private:
	int car_num;
	time_t dispatch_time;
	time_t departure_time;
	bool for_disabled;

public:
	//Car();
	Car(int car_num);
	Car(const Car&);
	~Car();
	int get_Car_num();
	double get_dispatch_time();
	double get_departure_time();
	void set_dispatch_time();
	void set_departure_time();
	int calculate_fee();
};
#endif