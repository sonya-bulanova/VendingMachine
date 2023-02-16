#pragma once
#include <iostream>
#include "PersonalComputer.h"
#include "Smartphone.h"

class Tablet final : public PersonalComputer, Smartphone {
public:
	Tablet(double _price, double _diagonal, int _memory, double _weight);
	void show_stats();
	~Tablet() {};
private:
	double _price;
	double _weight;
	int _memory;
	double _diagonal;
};
