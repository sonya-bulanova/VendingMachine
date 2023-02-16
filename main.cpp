#include <iostream>
#include "Technics.h"
#include "PersonalComputer.h"
#include "Smartphone.h"
#include "Tablet.h"


int main()
{
	Technics* technics[4];
	technics[0] = new PersonalComputer(109000, 1024, "acer nitro 5");
	technics[1] = new Smartphone(39990, 6.3);
	technics[2] = new PersonalComputer(49990, 512, "lenovo");
	technics[3] = new Tablet(17990, 11.4, 128, 0.8);

	std::cout << "Choose product: 1 - PC #1, 2 - smartphone, 3 - PC #2, 4 - tablet" << std::endl;
	int choice;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		technics[0]->show_stats();
		break;

	case 2:
		technics[1]->show_stats();
		break;

	case 3:
		technics[2]->show_stats();
		break;

	case 4:
		technics[3]->show_stats();
		break;
	default:
		std::cout << "Choose product: " << std::endl;
		break;
	}
	delete technics[0];
	delete technics[1];
	delete technics[2];
	delete technics[3];
	return 0;
}
