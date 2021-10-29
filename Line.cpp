#include "Line.h"

Point::Line::Line(Point pOne_, Point pTwo_)
	: pOne(pOne_), pTwo(pTwo_)
{
}

Point::Line::~Line()
{
	delete[] pointsInLine;
}
Point* Point::Line::buildArray()
{
	return 0;
}

int Point::Line::getDistance_X()
{
	if (pOne.x - pTwo.x > 0) {
		return pOne.x - pTwo.x;
	}
	else {
		return pTwo.x - pOne.x;
	}
}

int Point::Line::getDistance_Y()
{
	if (pOne.y - pTwo.y > 0) {
		return pOne.y - pTwo.y;
	}
	else {
		return pTwo.y - pOne.y;
	}
}

void Point::Line::set_n()
{
	if (getDistance_X() > getDistance_Y()) {
		n = getDistance_X() - 1;
	}
	else {
		n = getDistance_Y() - 1;
	}
}