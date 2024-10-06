#include <iostream>
#include <Windows.h>
#include <tuple>

int sleepDuration();
enum MouseButton { NONE, LEFT, RIGHT, MIDDLE };
MouseButton getMouseButton();
char customKey();
void autoClicker(MouseButton selectedButton, char selectedKey, int CPS);

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
	int CPS = sleepDuration();
	MouseButton selectedButton = getMouseButton();
	char selectedKey = customKey();
	autoClicker(selectedButton, selectedKey, CPS);
	return 0;
}

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

MouseButton getMouseButton() {
	MouseButton button = NONE;
	std::cout << "Select a mouse button to use: LEFT, RIGHT, or MIDDLE. Click your selection.\n";

	while (button == NONE) {
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
			button = LEFT;
			std::cout << "Selected Mouse Button: LEFT\n\n";
		}
		else if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
			button = RIGHT;
			std::cout << "Selected Mouse Button: RIGHT\n\n";
		}
		else if (GetAsyncKeyState(VK_MBUTTON) & 0x8000) {
			button = MIDDLE;
			std::cout << "Selected Mouse Button: MIDDLE\n\n";
		}
	}

	return button;
}

char customKey() {
	char K;
	std::cout << "Press a key from 'A' to 'Z' or the SHIFT, CTRL, or ALT keys to use it as your autoclick key...\n";

	while (true) {
		for (char key = 'A'; key <= 'Z'; key++) { // Loop through A to Z Keys
			if (GetAsyncKeyState(key) & 0x8000) {
				K = key;
				std::cout << "Selected Key: '" << K << "'\n\n";
				Sleep(200);
				std::cout << "Hold '" << K << "' to enable autoclicking (release to stop).\n";
				return K;
			}
		}

		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) { // Shift Key
			std::cout << "Selected Key: SHIFT\n\n";
			Sleep(200);
			std::cout << "Hold SHIFT to enable autoclicking (release to stop).\n";
			return VK_SHIFT;
		}

		if (GetAsyncKeyState(VK_CONTROL) & 0x8000) { // Ctrl Key
			std::cout << "Selected Key: CTRL\n\n";
			Sleep(200);
			std::cout << "Hold CTRL to enable autoclicking (release to stop).\n";
			return VK_CONTROL;
		}

		if (GetAsyncKeyState(VK_MENU) & 0x8000) { // Alt key
			std::cout << "Selected Key: ALT\n\n";
			Sleep(200);
			std::cout << "Hold ALT to enable autoclicking (release to stop).\n";
			return VK_MENU;
		}

		/* if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) { // Left Shift Key
			std::cout << "Selected Key: LEFT SHIFT\n\n";
			Sleep(200);
			std::cout << "Hold LEFT SHIFT to enable autoclicking (release to stop).\n";
			return VK_LSHIFT;
		}

		if (GetAsyncKeyState(VK_LCONTROL) & 0x8000) { // Left Ctrl Key
			std::cout << "Selected Key: LEFT CTRL\n\n";
			Sleep(200);
			std::cout << "Hold LEFT CTRL to enable autoclicking (release to stop).\n";
			return VK_LCONTROL;
		}

		if (GetAsyncKeyState(VK_LMENU) & 0x8000) { // Left Alt key
			std::cout << "Selected Key: LEFT ALT\n\n";
			Sleep(200);
			std::cout << "Hold LEFT ALT to enable autoclicking (release to stop).\n";
			return VK_LMENU;
		} */
		
		/* if (GetAsyncKeyState(VK_RSHIFT) & 0x8000) { // Right Shift Key
			std::cout << "Selected Key: RIGHT SHIFT\n\n";
			Sleep(200);
			std::cout << "Hold RIGHT SHIFT to enable autoclicking (release to stop).\n";
			return VK_RSHIFT;
		}

		if (GetAsyncKeyState(VK_RCONTROL) & 0x8000) { // Right Ctrl Key
			std::cout << "Selected Key: RIGHT CTRL\n\n";
			Sleep(200);
			std::cout << "Hold RIGHT CTRL to enable autoclicking (release to stop).\n";
			return VK_RCONTROL;
		}

		if (GetAsyncKeyState(VK_RMENU) & 0x8000) { // Right Alt key
			std::cout << "Selected Key: RIGHT ALT\n\n";
			Sleep(200);
			std::cout << "Hold RIGHT ALT to enable autoclicking (release to stop).\n";
			return VK_RMENU;
		} */
	}
}

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
