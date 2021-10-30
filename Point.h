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
private:
	int x;
	int y;
};