#include <iostream>

using namespace std;

class Point2D {
    int x;
    int y;
public:
    Point2D(int _x = 0, int _y = 0) : x(_x), y(_y) {;}
    void setPoint2D(int _x, int _y) { x = _x; y = _y; }
    int getX() { return x; }
    int getY() { return y; }
};

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
    Point2D center;
    double radius;
public:
    Circle() {;}
    Circle(Point2D c, double r) : center(c), radius(r) {;}
    double area() { return 3.14 * radius * radius; }
};

class Triangle : public Shape {
    Point2D *vertices;
public:
    Triangle() { vertices = new Point2D[3]; }
    Triangle(Point2D* vec) {
        vertices = new Point2D[3];
        for(int i = 0; i < 3; i++)
            vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
    }
    ~Triangle() { delete [] vertices; }
    double area() {
        double triArae;
        triArae = (vertices[0].getX() * (vertices[1].getY() - vertices[2].getY()) +
                  vertices[1].getX() * (vertices[2].getY() - vertices[0].getY()) +
                  vertices[2].getX() * (vertices[0].getY() - vertices[1].getY())) / 2.0;
        return (triArae > 0) ? triArae : (-1) * triArae;
    }
};

class Rectangle : public Shape {
    Point2D *vertices;
public:
    Rectangle() { vertices = new Point2D[4]; }
    Rectangle(Point2D* vec) {
        vertices = new Point2D[4];
        for(int i = 0; i < 4; i++)
            vertices[i].setPoint2D(vec[i].getX(), vec[i].getY());
    }
    ~Rectangle() { delete [] vertices; }
    double area() {
        int width = vertices[2].getX() - vertices[0].getX();
        int height = vertices[2].getY() - vertices[0].getY();
        return width * height;
    }
};

int main() {
    Point2D pt(3,4);
    Circle cir(pt, 5);
    Point2D *vec = new Point2D[3];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(1,6);
    vec[2].setPoint2D(8,1);
    Triangle tri(vec);
    delete []vec;
    vec = new Point2D [4];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(6,6);
    vec[3].setPoint2D(1,6);
    Rectangle rect(vec);
    delete [] vec;

    Shape *collection[3];
    collection[0] = &cir;
    collection[1] = &tri;
    collection[2] = &rect;
    cout << "Area of Circle: " << collection[0]->area() << endl;
    cout << "Area of Triangle: " << collection[1]->area() << endl;
    cout << "Area of Rectangle: " << collection[2]->area() << endl;
    return 0;
}
