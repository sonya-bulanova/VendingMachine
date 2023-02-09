#pragma once
#include <iostream>
#include "cstring"
#include "SnackSlot.h"
//class SnackSlot;

class Machine
{
public:
	Machine();
	Machine(int slotCount);
	~Machine();
	void addSlot(SnackSlot* s_slot);
	int getEmptySlotsCount();
private:
	int slotCount;
	SnackSlot* slot;
};
