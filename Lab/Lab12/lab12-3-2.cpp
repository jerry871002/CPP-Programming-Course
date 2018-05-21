// lab12-3-2.cpp
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
        //cout << "New X and Y" << endl;
    }
    Point2D(Point2D& pt) {
        x = new int(*(pt.x));
        y = new int(*(pt.y));
        //cout << "New X and Y (Copy constructor)" << endl;
    }
    virtual ~Point2D() { delete x; delete y; /*cout << "Delete X and Y" << endl;*/ }
    void print() { cout << *x << "," << *y; }
    void setPoint2D(int _x, int _y) { *x = _x; *y = _y; }
    int getX() { return *x; }
    int getY() { return *y; }
};

class Shape {
protected:
    int color;
public:
    virtual void draw() = 0; // Pure virtual function
    virtual bool is_closed() = 0; // Pure virtual function
    virtual ~Shape(){}
};

class Polygon: public Shape {
public:
    bool is_closed() { return true; }
};

class Triangle: public Polygon {
public:
    // constructor for Triangle
    Triangle(Point2D* vec = 0, int c = 0) {
        color = c;
        vertices = new Point2D[3];
        for(int i = 0; i < 3; i++)
            vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
    }
    ~Triangle() { delete [] vertices; }
    void draw() {
        cout << "Color: " << color << endl;
        for(int i = 0; i < 3; i++) {
            vertices[i].print();
            cout << endl;
        }
    }
private:
    Point2D *vertices;
};

int main()
{
    Point2D *vec = new Point2D[3];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(1,8);
    Triangle t(vec,255);
    delete []vec;
    t.draw();
    return 0;
}
