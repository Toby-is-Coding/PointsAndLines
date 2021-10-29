#pragma once
class Point
{
public:
	Point();
	~Point();

	int getX(); //x
	void setX(const int inpX);
	int getY(); //y
	void setY(const int inpY);
	int getMax_X();
	int getMax_Y();
	friend void display(Point* points, int amountOfPoints);
	class Line;
private:
	const int max_X;
	const int max_Y;
	int x;
	int y;
};