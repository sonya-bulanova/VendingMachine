#include "Snack.h"

Snack::Snack() {
	this->SnackName = "Water";
	this->SnackPrice = 0.99;
	this->calories = 0;
}

Snack::Snack(std::string name) {
	this->SnackName = name;
	this->SnackPrice = 0.99;
	std::transform(SnackName.begin(), SnackName.end(), SnackName.begin(), tolower);
	if (SnackName == "water") {
		this->calories = 0;
	}
	else {
		this->calories = 500;
	}
}

Snack::Snack(std::string name, double price) {
	this->SnackName = name;
	this->SnackPrice = price;
	std::transform(SnackName.begin(), SnackName.end(), SnackName.begin(), tolower);
	if (SnackName == "water") {
		this->calories = 0;
	}
	else {
		this->calories = 500;
	}
}

Snack::Snack(std::string name, double price, double calories) {
	this->SnackName = name;
	this->SnackPrice = price;
	this->calories = calories;
}

Snack::Snack(const Snack& snack) {
	this->SnackName = snack.SnackName;
	this->SnackPrice = snack.SnackPrice;
	this->calories = snack.calories;
}

Snack::~Snack() {

}

std::string Snack::GetName() {
	return SnackName;
}

double Snack::GetPrice() {
	return SnackPrice;
}

double Snack::GetCalories() {
	return calories;
}

void Snack::SetName(std::string name) {
	this->SnackName = name;
}

void Snack::SetPrice(double price) {
	this->SnackPrice = price;
}

void Snack::SetCalories(double calories) {
	this->calories = calories;
}