
#include "utilities.h"
#include <iostream>
#include <Windows.h>

int sleepDuration() {
	int CPS;
	bool exitFlag = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
	do {
		std::cout << "Select your clicks per second (CPS) from 1 to 50: ";
		std::cin >> CPS;

		if (CPS >= 1 && CPS <= 50) {
			std::cout << "Selected CPS: " << CPS << "\n\n";
			exitFlag = true;
		}

		else {
			std::cout << "Please choose from 1 to 50 only. Try again.\n\n";
		}
	} while (!exitFlag);

	return CPS;
}