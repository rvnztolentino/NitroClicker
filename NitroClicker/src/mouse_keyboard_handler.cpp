
#include "utilities.h"
#include <iostream>
#include <Windows.h>

MouseButton getMouseButton() {
	MouseButton button = NONE;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
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
