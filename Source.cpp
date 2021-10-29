#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Colours.h"

using namespace std;

Point* buildArray(int* amountOfPoints);
void buildPoint(Point* currentPoint);

Point* buildArray(int* amountOfPoints)
{
	cout << "How many points will we make?" << endl;
	bool legalValue = false;
	while (!legalValue) {
		cin >> *amountOfPoints;
		if (*amountOfPoints <= 0) {
			cout << RED <<"Illegal value." << NRM << endl;
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
		if (x > 0 && x < (*currentPoint).getMax_X()) {
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
		if (y > 0 && y < (*currentPoint).getMax_Y()) {
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
	Point* ptr_to_array = buildArray(&amountOfPoints);
	int nLines;
	//for loop to create the lines

	display(ptr_to_array, amountOfPoints);

	delete[] ptr_to_array;
	return 0;
}
