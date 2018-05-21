//lab12-3.cpp
#include <iostream>

using std::cout;
using std::endl;

class Shape {
protected:
    int color;
public:
    virtual void draw() = 0; // Pure virtual function
    virtual bool is_closed() = 0; // Pure virtual function
    virtual ~Shape(){}
};

int main()
{
    // The object of an abstract class cannot be defined.
    // It is illegal to define as “Shape s;”
    Shape s;
    return 0;
}
