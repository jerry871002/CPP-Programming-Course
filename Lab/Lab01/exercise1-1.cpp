//inline function

#include <iostream>

#define PI 3.1415

inline float area(float r) {return r * r * PI;}

using namespace std;

int main(){
	float radius;
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	
	cout << "The area of the circle is " << area(radius) << endl;
	return 0;
}

