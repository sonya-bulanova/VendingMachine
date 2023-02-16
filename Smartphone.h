#pragma once
#include <iostream>
#include "Technics.h"

class Smartphone : virtual public Technics {
public:
	Smartphone(double _price, double _diagonal);
	virtual ~Smartphone() {}
	void show_stats() override;

private:
	double _price;
	double _diagonal;
};

