#pragma once
#include "Point.h"
class Point::Line
{
public:
	Line(Point pOne_, Point pTwo_);
	~Line();
	Point* buildArray();
	int getDistance_X(); //distance of the line on the x axis
	int getDistance_Y(); //distance of the line on the y axis
	void set_n();
private:
	Point pOne;
	Point pTwo;
	int n;
	Point* pointsInLine = new Point[n];
};