// lab11-2
#include <iostream>
using namespace std;

class Point2D {
public:
    Point2D(int a = 0, int b = 0) { x = a; y = b; }
    void display() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
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
};

int main() {
    Point2D p;
    Point2D *vec = new Point2D[3];
    Circle_in_Triangle ct(p, 0, vec);
    ct.draw();
    return 0;
}
