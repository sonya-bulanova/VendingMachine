#include <iostream>
#include "Technics.h"
#pragma once
class PersonalComputer : virtual public Technics
{
public:
	PersonalComputer(double _price, int _memory, std::string _model);
	void show_stats() override;
	virtual ~PersonalComputer() {};
protected:
	double _price;
	int _memory;
	std::string _model;
};

