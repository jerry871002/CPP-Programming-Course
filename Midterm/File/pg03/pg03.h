//pg03.h
#ifndef _PG03_H_
#define _PG03_H_
#include <iostream>
#include <math.h>
using namespace std;
class Point{
    public:
        Point();
        Point(int);   
        void setCord(double *);
        double getCord(int);
        ~Point(){delete []cordinates;}
        const Point& operator=(const Point);
    private:
        double *cordinates;
        int dimension;
};

class Line{
    public:
        Line(int);
        void setPoint(double*, double*);
        void calDist();
        void printDist();
    private:
        double distance;
        int dimension;
        Point point1, point2;
};

#endif 