#include <iostream>
#include "Point.h"
#include "Colours.h"

using namespace std;

Point* buildArray(int* amountOfPoints);
void buildPoint(Point* currentPoint);
void display(Point* points, int amountOfPoints);

Point* buildArray(int* amountOfPoints)
{
	cout << "How many points will we make?" << endl;
	cin >> *amountOfPoints;
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
	display(ptr_to_array, amountOfPoints);

	delete[] ptr_to_array;
	return 0;
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
			cout << currentChar;
		}
		cout << endl;
	}
}