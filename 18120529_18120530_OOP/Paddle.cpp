#include "Paddle.h"



Paddle::Paddle()
{
	x = y = 0;
}


Paddle::~Paddle()
{
}

Paddle::Paddle(int posX, int posY) : Paddle()
{
	X = posX;
	Y = posY;
	x = X;
	y = Y;
}

void Paddle::Reset()
{
	x = X;
	y = Y;
}

int Paddle::getX(){ 
	return x; 
}
int Paddle::getY() {
	return y; 
}

void Paddle::moveUp() {
	y--;
}
void Paddle::moveDown() {
	y++; 
}
