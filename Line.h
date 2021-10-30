#pragma once
#include "Point.h"
class Line
{
public:
	Line();
	Line(Point pOne_, Point pTwo_);
	~Line();
	int getDistance_X(); //distance of the line on the x axis
	int getDistance_Y(); //distance of the line on the y axis
	char getDirection();
	int getLongestAxis();
	int getShortestAxis();
	Point* getPointsInLine(); //getter func for pointsInLine array
	void setPointsInLine(); //set all the points in line (build pointsInLine array)
	void buildPointInLine(Point* currentPointIL); //set where given point in line goes
	void calLocationForPIL(bool* xTyF, bool* left_up, bool* sh_left_up); //calculate location for point in line
	friend void display(Point* points, int amountOfPoints, Line* lines, int amountOfLines);
private:
	Point pOne;
	Point pTwo;
	char direction; //to more accurately display the line, i.e more horizontal than vertical or opposite
	int n; //n is the longest distance between axes X and Y - amount of points to output in the line
	Point* pointsInLine = new Point[n]; //all the points making up the line
};