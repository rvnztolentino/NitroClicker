
#include "utilities.h"
#include <iostream>

int main() {
	nitro(); // Logo display
	int CPS = sleepDuration(); // CPS setting
	MouseButton selectedButton = getMouseButton(); // Mouse button selection
	char selectedKey = customKey(); // Keybind select
	bool statusIndicator = displaySetting(); // Enable or disable status indicators
	autoClicker(selectedButton, selectedKey, CPS, statusIndicator);  // Start the autoclicker

	return 0;
}
