#include "Line.h"

Line::Line()
	: n(1), pointsInLine(nullptr)
{
}

Line::Line(Point pOne_, Point pTwo_)
	: pOne(pOne_), pTwo(pTwo_), n(getLongestAxis())
{
}

Line::~Line()
{
	delete[] pointsInLine;
}

int Line::getDistance_X()
{
	if (pOne.getX() - pTwo.getX() > 0) {
		return pOne.getX() - pTwo.getX();
	}
	else {
		return pTwo.getX() - pOne.getX();
	}
}

int Line::getDistance_Y()
{
	if (pOne.getY() - pTwo.getY() > 0) {
		return pOne.getY() - pTwo.getY();
	}
	else {
		return pTwo.getY() - pOne.getY();
	}
}

char Line::getDirection()
{
	return direction;
}

int Line::getLongestAxis()
{
	if (getDistance_X() > getDistance_Y()) {
		return getDistance_X() - 1; //-1 because we want it to be equal to the num of points we need to print.
	}
	else {
		return getDistance_Y() - 1;
	}
}

int Line::getShortestAxis()
{
	if (getDistance_X() < getDistance_Y()) {
		return getDistance_X();
	}
	else {
		return getDistance_Y();
	}
}

Point* Line::getPointsInLine() //getter func for pointsInLine array
{
	return pointsInLine;
}

void Line::setPointsInLine() //(build array)
{
	for (int i = 0; i < n; i++) {
		buildPointInLine(&pointsInLine[i]);
	}
}

//overloading roundUpwards() func to account for if division resulted in an int desiring no change, or a double needing to be rounded upwards.
int roundUpwards(double d) { return d + 1; }
int roundUpwards(int n) { return n; }

void Line::buildPointInLine(Point* currentPointIL)
{
	/* explaining nUntilCont -
	* num of points to print in a row before moving the printing location
	* one step closer to the destination point on the shortest axis distance.
	* --using static to keep incrementing the value after each loop of this function
	* and keep the value after function ends.
	* --using auto to recognize whether or not result is double or int, and overload
	* roundUpwards() func accordingly. vv */
	static auto nUntilCont = roundUpwards(getLongestAxis() / getShortestAxis()); //example: 5/2 = 2.5 -> 3; meaning after printing 3 points, continue on the shortest axis.
	
	bool xTyF; //x - True, y - False | Which distance is longer?
	bool left_up; //is pTwo on the left/above pOne? Depending on which axis is longest.
	bool sh_left_up; //same as above ^ but depending on which axis is shortest.
	calLocationForPIL(&xTyF, &left_up, &sh_left_up); //calculate location
	
	//set location:
	if (xTyF) {
		direction = '-'; //line direction horizontal
		if (left_up) {
			(*currentPointIL).setX(pOne.getX() - 1); //inch to the left by 1
			if (nUntilCont == 0) { //if time has come to continue inching toward desired point on shortest axis length
				if (sh_left_up) {
					(*currentPointIL).setY(pOne.getY() - 1); //inch upwards by 1
				}
				else {
					(*currentPointIL).setY(pOne.getY() + 1); //inch downwards by 1
				}
			}
		}
		else {
			(*currentPointIL).setX(pOne.getX() + 1); //inch to the right by 1
		}
	}
	else {
		direction = '|';
		if (left_up) {
			(*currentPointIL).setY(pOne.getY() - 1); //inch upwards by 1
			if (nUntilCont == 0) { //if time has come to continue inching toward desired point on shortest axis length
				if (sh_left_up) {
					(*currentPointIL).setX(pOne.getX() - 1); //inch to the left by 1
				}
				else {
					(*currentPointIL).setX(pOne.getX() + 1); //inch to the right by 1
				}
			}
		}
		else {
			(*currentPointIL).setY(pOne.getY() + 1); //inch downwards by 1
		}
	}
	if (nUntilCont == 0) {
		nUntilCont = roundUpwards(getLongestAxis() / getShortestAxis()); //reset
	}
	else {
		nUntilCont--; //1 less cycle of this func before continuing toward desired point on shortest axis
	}
}

void Line::calLocationForPIL(bool* xTyF, bool* left_up, bool* sh_left_up)
{
	if (getDistance_X() > getDistance_Y()) {
		*xTyF = true;
		if (pTwo.getX() < pOne.getX()) { //checking for longest axis
			*left_up = true;
		}
		else {
			*left_up = false;
		}
		if (pTwo.getY() < pOne.getY()) { //checking for shortest axis
			*sh_left_up = true;
		}
		else {
			*sh_left_up = false;
		}
	}
	else {
		*xTyF = false;
		if (pTwo.getY() < pOne.getY()) { //checking for longest axis
			*left_up = true;
		}
		else {
			*left_up = false;
		}
		if (pTwo.getX() < pOne.getX()) { //checking for shortest axis
			*sh_left_up = true;
		}
		else {
			*sh_left_up = false;
		}
	}
}