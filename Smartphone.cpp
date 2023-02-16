#include "Smartphone.h"

Smartphone::Smartphone(double _price, double _diagonal) : Technics() {
	this->_price = _price;
	this->_diagonal = _diagonal;
	//std::cout << " Smartphone created " << std::endl;
}

void Smartphone::show_stats(){
	std::cout << "Price: " << _price << " RUB" << std::endl;
	std::cout << "Diagonal " << _diagonal << " inches" << std::endl;
}
