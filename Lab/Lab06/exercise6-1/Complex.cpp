// Complex.cpp
#include <iostream>
#include "Complex.h"

using namespace std;

// Member-function definitions for class Complex. 
Complex::Complex() {

}

Complex::Complex(float realNum, float imageNum) {
	real = realNum;
	image = imageNum;
}

Complex Complex::operator+(Complex& c) {
	return Complex(real + c.real, image + c.image);
}

Complex Complex::operator-(Complex& c) {
	return Complex(real - c.real, image - c.image);
}

Complex Complex::operator*(Complex& c) {
	return Complex(real * c.real - image * c.image, \
				   real * c.image + image * c.real);
}

Complex Complex::operator/(Complex& c) {
	return Complex((real * c.real + image * c.image) \
				   / (c.real * c.real - c.image * c.image), \
				   (image * c.real - real * c.image) \
				   / (c.real * c.real - c.image * c.image));
}

void Complex::setComplexNumber(float realNum, float imageNum) {
	real = realNum;
	image = imageNum;
}

//friend functions
void printMeg(Complex& a, Complex& b, char c) {
	printComplex(a);
	cout << " " << c << " ";
	printComplex(b);
	cout << " = ";
}

void printComplex(Complex& c) {
	cout << "(" << c.real << ", " << c.image << ")";
}

Complex operator-(Complex& c) {
	return Complex((-1) * c.real, (-1) * c.image);
}