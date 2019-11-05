#pragma once
#include "WindowLibrary.h"

extern int speed;


class Ball
{
private:
	// tọa độ 
	int x; int y;
	// tọa độ gốc
	int X; int Y;
	eDir direction;
public:
	Ball();
	~Ball();
	Ball(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	int getX();
	int getY();
	eDir getDirection();
	void Move();


};

