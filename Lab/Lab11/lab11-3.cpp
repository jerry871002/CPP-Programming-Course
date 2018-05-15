// lab11-3.cpp
/* add area() for class Circle */
/* add area() for class Triangle */
#include <iostream>
using namespace std;

class Point2D {
public:
    Point2D(int a = 0, int b = 0) { x = a; y = b; }
    void display() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
    void setXY(int a, int b) { x = a; y = b; }
    int getX() { return x; }
    int getY() { return y; }
private:
    int x;
    int y;
};

class Circle {
public:
    Circle() {;}
    Circle(Point2D p, double r): center(p), radius(r) {;}
    void draw() {
        cout << "Center: ";
        center.display();
        cout << "Radius: " << radius << endl;
    }
    void setCenter(Point2D p) {
        center = p;
    }
    void setRadius(double r) {
        radius = r;
    }
    double area() {
        return radius * radius * 3.14;
    }
private:
    Point2D center;
    double radius;
};

class Triangle {
public:
    Triangle() { vertices = new Point2D[3]; }
    ~Triangle(){ delete [] vertices; }
    void draw() {
        cout << "Vertices:" << endl;
        for(int i = 0; i < 3; i++)
            vertices[i].display();
    }
    void setVertices(Point2D* p) {
        for(int i  = 0; i < 3; i++)
            vertices[i] = p[i];
    }
    double area() {
        double triArae;
        triArae = (vertices[0].getX() * (vertices[1].getY() - vertices[2].getY()) +
                  vertices[1].getX() * (vertices[2].getY() - vertices[0].getY()) +
                  vertices[2].getX() * (vertices[0].getY() - vertices[1].getY())) / 2;
        return (triArae > 0) ? triArae : (-1) * triArae;
    }
private:
    Point2D *vertices;
};

class Circle_in_Triangle: public Circle, public Triangle {
public:
    Circle_in_Triangle(Point2D p, double r, Point2D* v) {
        setCenter(p);
        setRadius(r);
        setVertices(v);
    }
    void draw() {
        Circle::draw();
        Triangle::draw();
    }
    double area() {
        return Triangle::area() - Circle::area();
    }
};

int main() {
    Point2D p(2, 2);
    Point2D *vec = new Point2D[3];

    vec[0].setXY(1, 1);
    vec[1].setXY(3, 1);
    vec[2].setXY(1, 6);

    Circle_in_Triangle ct(p, 1, vec);
    
    ct.draw();
    cout << "Area of Circle: " << ct.Circle::area() << endl;
    cout << "Area of Triangle: " << ct.Triangle::area() << endl;
    cout << "Area of Circle_in_Triangle: " << ct.Circle_in_Triangle::area() << endl;
    return 0;
}
