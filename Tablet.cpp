#include "Tablet.h"

Tablet::Tablet(double _price, double _diagonal, int _memory, double _weight) : Smartphone(_price, _diagonal), PersonalComputer(_price, _memory, "") {
	this->_price = _price;
	this->_diagonal = _diagonal;
	this->_memory = _memory;
	this->_weight = _weight;
}

void Tablet::show_stats() {
	std::cout << "Price: " << _price << " RUB" << std::endl;
	std::cout << "Memory: " << _memory << " Gb" << std::endl;
	std::cout << "Diagonal " << _diagonal << " inches" << std::endl;
	std::cout << "Weight: " << _weight << " kg" << std::endl;
}
