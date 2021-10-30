#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Colours.h"

using namespace std;

Point* p_buildArray(int* amountOfPoints);
void buildPoint(Point* currentPoint);
int getAOL(int amountOfPoints);
Line* l_buildArray(Point* points, int amountOfLines);

const int max_X = 40;
const int max_Y = 40;

Point* p_buildArray(int* amountOfPoints)
{
	cout << "How many points will we make?" << endl;
	bool legalValue = false;
	while (!legalValue) {
		cin >> *amountOfPoints;
		if (*amountOfPoints <= 0 || *amountOfPoints > max_X * max_Y) {
			cout << RED << "Illegal value." << endl;
		}
		else {
			legalValue = true;
		}
	}
	Point* points = new Point[*amountOfPoints];
	for (int i = 0; i < *amountOfPoints; i++) {
		buildPoint(&points[i]);
	}
	return points;
}

void buildPoint(Point* currentPoint)
{
	bool legalValue = false;
	int x;
	int y;
	while (!legalValue) {
		cout << NRM << "Enter point X: " << GRN;
		cin >> x;
		if (x > 0 && x < max_X) {
			legalValue = true;
		}
		else {
			cout << RED << "Illegal value." << NRM << endl;
		}
	}
	(*currentPoint).setX(x); //dereferences currentPoint to access setX func
	legalValue = false;
	while (!legalValue) {
		cout << NRM << "Enter point Y: " << GRN;
		cin >> y;
		if (y > 0 && y < max_Y) {
			legalValue = true;
		}
		else {
			cout << RED << "Illegal value." << NRM << endl;
		}
	}
	(*currentPoint).setY(y); //dereferences currentPoint to access setY func
	cout << NRM << endl;
}

int main()
{
	int amountOfPoints;
	Point* ptr_to_Parry = p_buildArray(&amountOfPoints); //build array of points

	int amountOfLines = getAOL(amountOfPoints); //AOL = AmountOfLines
	Line* ptr_to_Larry = l_buildArray(ptr_to_Parry, amountOfLines); //build array of lines

	display(ptr_to_Parry, amountOfPoints, ptr_to_Larry, amountOfLines);

	delete[] ptr_to_Parry, ptr_to_Larry;
	return 0;
}

int getAOL(int amountOfPoints)
{
	//if there's 1 point, there are 0 lines. 2 points = 1 line. Otherwise, x points = x lines vv
	if (amountOfPoints < 3) { //if it's less than 3, it must be either 1 or 2 - since it's a whole number which was made sure to be > 0 in p_buildArray()
		return amountOfPoints - 1;
	}
	else {
		return amountOfPoints;
	}
}

Line* l_buildArray(Point* points, int amountOfLines)
{
	if (amountOfLines == 0) { //cant make an array of 0 objects
		return nullptr; //return nullpointer
	}
	Line* lines = new Line[amountOfLines];
	for (int i = 0; i < amountOfLines; i++) {
		if (i != amountOfLines - 1 || amountOfLines == 1) { //a to b, b to c, c to d //accounting for the case of only 1 line: a to b, no need to then make b to a.
			lines[i] = Line(points[i], points[i + 1]);
		}
		else { //d to a
			lines[i] = Line(points[i], points[0]);
		}
		lines[i].setPointsInLine();
	}
	return lines;
}

void display(Point* points, int amountOfPoints, Line* lines, int amountOfLines)
{
	char currentChar;
	Point* pointsInLine = nullptr;
	for (int i = 0; i < max_Y; i++) { //for each column (y)
		for (int j = 0; j < max_X; j++) { //for each row (x)
			currentChar = ' ';
			for (int p = 0; p < amountOfPoints; p++) { //for each point
				if (points[p].getY() == i && points[p].getX() == j) {
					currentChar = 'o';
					cout << GRN;
				}
			}
			for (int l = 0; l < amountOfLines; l++) { //for each line
				pointsInLine = lines[l].getPointsInLine();
				for (int pointIL = 0; pointIL < lines[l].getLongestAxis(); pointIL++) { //for each point in line
					if (pointsInLine[pointIL].getY() == i && pointsInLine[pointIL].getX() == j) {
						currentChar = lines[l].getDirection(); //'-' or '|'
					}
				}
			}
			cout << currentChar;
			cout << NRM;
		}
		cout << endl;
	}
	delete[] pointsInLine;
}