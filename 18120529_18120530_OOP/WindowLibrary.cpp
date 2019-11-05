#include "WindowLibrary.h"
int speed = 100000000;
bool modeplayer = false;


void SetConsoleSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void removeCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void WindowInit()
{
	SetConsoleSize(800, 480);
	removeCursor();
}

void ModeMenu(bool &modeplayer)
{
	gotoxy(60 / 2, 20 / 2);
	cout << "01. NGUOI CHOI VOI MAY";
	gotoxy(30, 11);
	cout << "02. HAI NGUOI CHOI VOI NHAU";
	char mode = _getch();
	if (mode == '1')
		modeplayer = false;
	if (mode == '2')
		modeplayer = true;
	system("cls");

}

