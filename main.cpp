#include <iostream>
#include "Snack.h"
#include "SnackSlot.h"
#include "Machine.h"
int main()
{
    Snack* bounty = new Snack("Bounty");
    Snack* snickers = new Snack("Snickers");
    SnackSlot* slot = new SnackSlot(10); /*количество батончиков, которые помещаются в слот*/
    slot->addSnack(bounty); //Добавляем батончик в слот
    slot->addSnack(snickers);
    int slotCount = 15;
    Machine* machine = new Machine(slotCount); /*Количество слотов для снеков*/
    machine->addSlot(slot); // Помещаем слот обратно в аппарат

    std::cout << machine->getEmptySlotsCount(); // Должно выводить количество пустых слотов для снеков
    
    delete machine;
    delete slot;
    delete snickers;
    delete bounty;
}