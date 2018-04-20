#include <iostream>
#include <cmath>
#include "pg03.h"

Point::Point() {

}

Point::Point(int dim) {
	dimension = dim;
	cordinates = new double[dim];
	//std::cout << cordinates << endl;
}

void Point::setCord(double* somePoint) {
	for(int i = 0; i < dimension; i++) {
		cordinates[i] = somePoint[i];
		//std::cout << "cordinates[" << i << "] = " << cordinates[i] << endl;
	}
}

double Point::getCord(int x) {
	return cordinates[x];
}

const Point& Point::operator=(const Point somePoint) {
	dimension = somePoint.dimension;
	cordinates = new double[dimension];
	for(int i = 0; i < dimension; i++) {
		cordinates[i] = somePoint.cordinates[i];
	}
	return (*this);
}

Line::Line(int dim) {
	dimension = dim;
	point1 = Point(dim);
	point2 = Point(dim);	
}

void Line::setPoint(double* p1, double* p2) {	
	point1.setCord(p1);
	point2.setCord(p2);
}

void Line::calDist() {
	double distSum = 0;
	for(int i = 0; i < dimension; i++) {
		double distOne = point1.getCord(i) - point2.getCord(i);
		//cout <<"p1="<< &point1 << "\n" <<"p2="<< &point2 << endl;
		double distTwo = distOne * distOne;
		distSum += distTwo;
	}
	distance = sqrt(distSum);
}

void Line::printDist() {
	std::cout << "The distance between points is: " << distance << endl;
}