
#include "utilities.h"
#include <iostream>
#include <Windows.h>

void autoClicker(MouseButton selectedButton, char selectedKey, int CPS) {
	int sleepTime = 1000 / CPS;
	bool isAutoClickerActive = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 2);

	while (true) {
		if (GetAsyncKeyState(selectedKey) & 0x8000)
		{
			if (!isAutoClickerActive)
			{
				isAutoClickerActive = true;
				std::cout << "Autoclicker ENABLED (key held)\n";
			}
			if (selectedButton == LEFT) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}

			else if (selectedButton == RIGHT) {
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

			}

			else if (selectedButton == MIDDLE) {
				mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);

			}

			// Control the click speed (adjust Sleep time to your needs)
			Sleep(sleepTime);
		}

		else {
			if (isAutoClickerActive) {
				isAutoClickerActive = false;
				std::cout << "Autoclicker DISABLED (key released)\n";
			}
		}

		Sleep(10);
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