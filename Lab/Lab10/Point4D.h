// Point4D.h
#include <iostream>
#include "Point2D.h"

#ifndef POINT4D_H 
#define POINT4D_H 
class Point4D : public Point2D{
public:
	Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) {
		*this = Point2D(n1, n2);
		z = new int(n3);
		t = new int(n4);
	}
	Point4D& operator=(const Point2D& p2d) {
		setX(p2d.getX());
		setY(p2d.getY());
		return *this;
	}
	void display() const {
		Point2D::display();
		std::cout << "," << *z << "," << *t;
	}
private: 
	int *z; 
	int *t; 
}; 
#endif