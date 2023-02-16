#include "PersonalComputer.h"
PersonalComputer::PersonalComputer(double _price, int _memory, std::string _model) : Technics() {
	this->_price = _price;
	this->_memory = _memory;
	this->_model = _model;
	//std::cout << " PC created " << std::endl;
}

void PersonalComputer::show_stats() {
	std::cout << "Price: " << _price << " RUB" << std::endl;
	std::cout << "Memory: " << _memory << " Gb" << std::endl;
	std::cout << "Model name: " << _model << std::endl;
}

