#ifndef ALIEN_H
#define ALIEN_H

#include <windows.h>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

void initWindow();
void drawRect(int x, int y, int width, int height, COLORREF color);
void drawEllipse(int x, int y, int width, int height, COLORREF color);
void drawLine(int x1, int y1, int x2, int y2, COLORREF color);
void clearScreen();
void updateScreen();
int  getKeyInput();

#endif 