
#ifndef UTILITIES_H
#define UTILITIES_H

int sleepDuration();
enum MouseButton { NONE, LEFT, RIGHT, MIDDLE };
MouseButton getMouseButton();
char customKey();
void autoClicker(MouseButton selectedButton, char selectedKey, int CPS);
void nitro();

#endif