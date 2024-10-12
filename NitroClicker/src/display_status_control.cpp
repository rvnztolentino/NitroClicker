
#include "utilities.h"
#include <iostream>
#include <Windows.h>

bool displaySetting() {
	char K;
	bool statusIndicator = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);
	Sleep(200);
	std::cout << "\nWould you like to turn off the status indicators? (Press 'Y' for Yes or 'N' for No) ";

	while (true) {
		for (char key = 'A'; key <= 'Z'; key++) { // Loop through A to Z Keys
			if (GetAsyncKeyState(key) & 0x8000) {
				K = key;
				// std::cout << "Selected Key: '" << K << "'\n\n";
				if (K == 'Y') {
					std::cout << "\n-> ";
					SetConsoleTextAttribute(h, 10);
					std::cout << "OFF\n\n";
					return statusIndicator = false;
				}
				else if (K == 'N') {
					std::cout << "\n-> ";;
					SetConsoleTextAttribute(h, 10);
					std::cout << "ON\n\n";
					SetConsoleTextAttribute(h, 2);
					std::cout << "Autoclicker DISABLED (waiting for key press)\n";
					return statusIndicator = true;
				}
			}
		}
	}
}

void nitro() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);

	std::cout << R"(
		   .__  __                  
	  ____ |__|/  |________  ____  
	 /    \|  \   __\_  __ \/  _ \ 
	|   |  \  ||  |  |  | \(  <_> )
	|___|  /__||__|  |__|   \____/ 
		 \/  
	)" << "\n";
}
