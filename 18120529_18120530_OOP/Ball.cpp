#include "Ball.h"






Ball::Ball()
{
}


Ball::~Ball()
{
}

// constructor với tham số
Ball::Ball(int posX, int posY)
{
	X = posX;
	Y = posY;
	x = posX; y = posY;
	direction = STOP;
}

// Hàm tạo giá trị ban đầu cho tọa độ và hướng
void Ball::Reset()
{
	x = X;
	y = Y;
	direction = STOP;
}

// Hàm chuyển hướng di chuyển của bóng
void Ball::changeDirection(eDir d)
{
	direction = d;
}



// Hàm lấy tọa độ x
int Ball::getX() { 
	return x; 
}
// Hàm lấy tọa độ y
int Ball::getY() { 
	return y; 
}
// Hàm lấy hướng
eDir Ball::getDirection() { 
	return direction;
}

void Ball::Move()
{
	switch (direction)
	{
	case STOP:
		break;

	case LEFT:
		// vòng for tạo độ trễ cho việc cập nhật tọa độ x, coi như đang gián tiếp làm thay đổi tốc độ di chuyển của bóng
		for (int i = 0; i < speed; i++)
		{

		}
		x--;
		break;

	case RIGHT:
		for (int i = 0; i < speed; i++)
		{

		}
		x++;
		break;

	case UPLEFT:
		for (int i = 0; i < speed; i++)
		{

		}
		x--;
		y--;
		break;

	case DOWNLEFT:
		for (int i = 0; i < speed; i++)
		{

		}
		x--;
		y++;
		break;

	case UPRIGHT:
		for (int i = 0; i < speed; i++)
		{

		}
		x++;
		y--;
		break;

	case DOWNRIGHT:
		for (int i = 0; i < speed; i++)
		{

		}
		x++;
		y++;

		break;

	default:
		break;
	}
}
