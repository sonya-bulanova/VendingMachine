#include "SnackSlot.h"

SnackSlot::SnackSlot() {
	number_of_snakes = 8;
	snack = new Snack[number_of_snakes];
	for (int i = 0; i < number_of_snakes; i++) {
		this->snack[i] = Snack();
	}
}

SnackSlot::SnackSlot(int number_of_snacks) {
	number_of_snakes = number_of_snacks;
	snack = new Snack[number_of_snakes];
	for (int i = 0; i < number_of_snakes; i++) {
		this->snack[i] = Snack();
	}
}


SnackSlot::~SnackSlot() {
	if (snack) {
		delete[] snack;
	}
}

void SnackSlot::addSnack(Snack* food) {
	for (int i = 0; i < number_of_snakes; i++) {
		if (snack[i].GetName() != "Water") {
			continue;
		}
		else {
			this->snack[i] = *food;
		}
	}
	//std::cout << snack->GetName() << std::endl;
}

std::string SnackSlot::GetSnackName(int idx){
	return snack[idx].GetName();
}

void SnackSlot::PrintListOfSnacks() {
	for (int idx = 0; idx < number_of_snakes; idx++) {
		std::cout << "idx " << snack[idx].GetName() << std::endl;
	}
}
