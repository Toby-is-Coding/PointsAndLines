#include "Point.h"

Point::Point()
	: max_X(40), max_Y(40)
{
}

Point::~Point()
{
}

int Point::getX()
{
	return x;
}

void Point::setX(const int inpX)
{
	x = inpX;
}

int Point::getY()
{
	return y;
}

void Point::setY(const int inpY)
{
	y = inpY;
}

int Point::getMax_X()
{
	return max_X;
}

int Point::getMax_Y()
{
	return max_Y;
}
