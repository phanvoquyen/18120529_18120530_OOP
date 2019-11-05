#pragma once
#include <iostream>
#include "time.h"
#include "conio.h"
#include "windows.h"
extern int speed;
extern bool modeplayer;
enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

using namespace std;
void SetConsoleSize(int width, int height);
void removeCursor();
void gotoxy(int x, int y);
void TextColor(int x);
void WindowInit();
void ModeMenu(bool &modeplayer);


