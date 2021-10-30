#include "Point.h"
#include <iostream>

Point::Point()
	: x(), y()
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