#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include "Snack.h"

class Snack;

class SnackSlot
{
public:
	SnackSlot();
	SnackSlot(int number_of_snacks);
	~SnackSlot();
	void addSnack(Snack* food);
	void PrintListOfSnacks();
	std::string GetSnackName(int idx);
private:
	Snack* snack;
	int number_of_snakes;
};
