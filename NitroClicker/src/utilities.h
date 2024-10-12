
#ifndef UTILITIES_H
#define UTILITIES_H

int sleepDuration();
enum MouseButton { NONE, LEFT, RIGHT, MIDDLE };
MouseButton getMouseButton();
char customKey();
bool displaySetting();
void autoClicker(MouseButton selectedButton, char selectedKey, int CPS, bool statusIndicator);
void nitro();

#endif
