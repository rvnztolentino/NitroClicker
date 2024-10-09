
#include "utilities.h"
#include <iostream>

int main() {
	nitro();
	int CPS = sleepDuration();
	MouseButton selectedButton = getMouseButton();
	char selectedKey = customKey();
	autoClicker(selectedButton, selectedKey, CPS);

	return 0;
}