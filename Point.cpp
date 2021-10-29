#include "Point.h"
#include <iostream>

Point::Point()
	: max_X(40), max_Y(40), x(), y()
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

void display(Point* points, int amountOfPoints)
{
	char currentChar;
	for (int i = 0; i <= points[0].getMax_Y(); i++) { //for each column (y)
		for (int j = 0; j <= points[0].getMax_X(); j++) { //for each row (x)
			currentChar = ' ';
			for (int p = 0; p < amountOfPoints; p++) { //for each point
				if (points[p].getY() == i && points[p].getX() == j) {
					currentChar = 'o';
				}
			}
			std::cout << currentChar;
		}
		std::cout << std::endl;
	}
}
