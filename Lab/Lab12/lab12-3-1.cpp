// lab12-3-1.cpp
#include <iostream>

using namespace std;

class Point2D
{
private:
    int *x;
    int *y;
public:
    Point2D(int _x = 0, int _y = 0) {
        x = new int(_x);
        y = new int(_y);
        cout << "New X and Y" << endl;
    }
    Point2D(Point2D& pt) {
        x = new int(*(pt.x));
        y = new int(*(pt.y));
        cout << "New X and Y (Copy constructor)" << endl;
    }
    virtual ~Point2D() { delete x; delete y; cout << "Delete X and Y" << endl; }
    void print() { cout << *x << "," << *y; }
};

class Shape {
protected:
    int color;
public:
    virtual void draw() = 0; // Pure virtual function
    virtual bool is_closed() = 0; // Pure virtual function
    virtual ~Shape(){}
};

class Circle : public Shape {
public:
    // constructor of Circle.
    Circle() {;}
    Circle(Point2D pt, double r, int c) : center(pt), radius(r), color(c) {;}
    void draw() {
        cout << "Color: " << color << endl;
        cout << "Center: ";
        center.print();
        cout << endl;
        cout << "Radius: " << radius << endl;
    }
    bool is_closed() { return true; }
private:
    Point2D center;
    double radius;
    int color;
};

int main() {
    Point2D pt(3,4);
    cout << "------------------" << endl;
    Circle c(pt,5,255);
    cout << "------------------" << endl;
    c.draw();
    return 0;
}
