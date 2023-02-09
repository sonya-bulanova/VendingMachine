#include "Machine.h"

Machine::Machine() {
	this->slotCount = 8;
	this->slot = new SnackSlot;
	for (int i = 0; i < slotCount; i++) {
		this->slot[i] = SnackSlot();
	}
}

Machine::Machine(int slotCount) {
	this->slotCount = slotCount;
	this->slot = new SnackSlot;
	for (int i = 0; i < slotCount; i++) {
		this->slot[i] = SnackSlot();
	}
}

Machine::~Machine(){
	if (slot) {
		delete[] slot;
	}
}

void Machine::addSlot(SnackSlot* s_slot){
	for (int i = 0; i < slotCount; i++) {
		if (slot[i].GetSnackName(i) == SnackSlot().GetSnackName(i)) {
			this->slot[i] = *s_slot;
		}
	}
	//std::cout << snack->GetName() << std::endl;
}

int Machine::getEmptySlotsCount(){
	int counter = 0;
	for (int i = 0; i < slotCount; i++){
		if ((slot[i].GetSnackName(i) == SnackSlot().GetSnackName(i))) {
			counter++;
		}
	}
	return counter;
}
