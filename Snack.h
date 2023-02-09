#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

class Snack
{
public:
	Snack();
	Snack(std::string name);
	Snack(std::string name, double price);
	Snack(std::string name, double price, double calories);
	Snack(const Snack& snack);
	~Snack();

	std::string GetName();
	double GetPrice();
	double GetCalories();

	void SetName(std::string name);
	void SetPrice(double price);
	void SetCalories(double calories);
private:
	double SnackPrice;
	std::string SnackName;
	double calories;
};

