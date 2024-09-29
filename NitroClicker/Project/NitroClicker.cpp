#include <iostream>
#include <Windows.h>

// void userSelection();
int sleepDuration();
char customKey();
void autoClicker(char selectedKey, int CPS);

int main() {
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
	// userSelection();
	int CPS = sleepDuration();
	char selectedKey = customKey();
	autoClicker(selectedKey, CPS);
	return 0;
}

/* void userSelection() {
	std::cout << "Hold '" << customKey << "' to enable autoclicking (release '" << customKey << "' to stop clicking)\n";

} */

int sleepDuration() {
	int CPS;
	bool exitFlag = false;
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

char customKey() {
	char K;
	std::cout << "Press a key from 'A' to 'Z' to choose it as your autoclick key...\n";

	while (true) {
		for (char key = 'A'; key <= 'Z'; key++) { // Loop through A to Z
			if (GetAsyncKeyState(key) & 0x8000) {
				K = key;
				std::cout << "Selected Key: '" << K << "'\n\n";
				Sleep(200);

				return K;
			}
		}
	}
}

void autoClicker(char selectedKey, int CPS) {
	int sleepTime = 1000 / CPS;
	bool isAutoClickerActive = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Hold '" << selectedKey << "' to enable autoclicking (release to stop).\n";
	SetConsoleTextAttribute(h, 2);

	while (true) {
		if (GetAsyncKeyState(selectedKey) & 0x8000)
		{
			if (!isAutoClickerActive)
			{
				isAutoClickerActive = true;
				std::cout << "Autoclicker enabled (holding '" << selectedKey << "')\n";
			}

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			// Control the click speed (adjust Sleep time to your needs)
			Sleep(sleepTime);
		}

		else {
			if (isAutoClickerActive) {
				isAutoClickerActive = false;
				std::cout << "Autoclicker disabled (released '" << selectedKey << "')\n";
			}
		}

		Sleep(10);
	}
}
