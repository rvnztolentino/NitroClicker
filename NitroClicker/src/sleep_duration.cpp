
#include "utilities.h"
#include <iostream>
#include <Windows.h>

int sleepDuration() {
	int CPS;
	bool exitFlag = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
	do {
		std::cout << "Select your clicks per second (CPS): ";
		std::cin >> CPS;
		if (CPS >= 1 && CPS <= 100) {
			std::cout << "Selected CPS: " << CPS << "\n\n";
			exitFlag = true;
		}

		else if (CPS > 100) {
			CPS = 100; // Set to Max (100 CPS) if user intended rate exceeds
			std::cout << "Selected CPS: " << CPS << " (MAX)" << "\n\n";
			exitFlag = true;
		}

		else if (CPS < 1) { // Set to Min (1 CPS) if user intended rate exceeds
			CPS = 1;
			std::cout << "Selected CPS: " << CPS << " (MIN)" << "\n\n";
			exitFlag = true;
		}

		else {
			std::cout << "\n\n";
		}
	} while (!exitFlag);

	return CPS;
}
