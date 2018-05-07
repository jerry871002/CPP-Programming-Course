// Point2D.h
#include <iostream>

#ifndef POINT2D_H 
#define POINT2D_H 
class Point2D {
public:
	Point2D(int n1 = 0, int n2 = 0) {
		x = new int(n1);
		y = new int(n2);
	}
	Point2D(const Point2D& p2d) {
		x = new int;
		y = new int;
		*x = *(p2d.x);
		*y = *(p2d.y);
	}
	Point2D& operator=(const Point2D& p2d) {
		*x = *(p2d.x);
		*y = *(p2d.y);
		return *this;
	}
	void display() const {
		std::cout << *x << "," << *y;
	}
	void setX(int num) {*x = num;}
	void setY(int num) {*y = num;}
	int getX() const {return *x;}
	int getY() const {return *y;}
private: 
	int *x; 
	int *y; 
}; 
#endif