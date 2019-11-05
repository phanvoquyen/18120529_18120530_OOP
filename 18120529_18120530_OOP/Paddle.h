#pragma once
#include "WindowLibrary.h"

extern int speed;


class Paddle
{
private:
	int x; int y;
	int X; int Y;
public:
	Paddle();
	~Paddle();
	Paddle(int posX, int posY);
	void Reset();
	int getX();
	int getY();
	void moveUp();
	void moveDown();
};

