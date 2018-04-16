// Complex.cpp
#include <iostream>
#include "Complex.h"
using namespace std;
// Member-function definitions for class Complex. 
Complex::Complex(): real(0), image(0) {
}

Complex::Complex(float realNum, float imageNum): real(realNum), image(imageNum) {
}

Complex::Complex(const Complex& old) {
	real = old.real;
	image = old.image;
}

void Complex::printComplex() {
	cout << "(" << real << "," << image << ")";
}

void Complex::assign(float realNum, float imageNum) {
	real = realNum;
	image = imageNum;
}

void Complex::assignReal(float realNum) {
	real = realNum;
}

void Complex::assignImage(float imageNum) {
	image = imageNum;
}

float Complex::getReal() {
	return real;
}

float Complex::getImage() {
	return image;
}

Complex Complex::add(Complex x) {
	float realNum, imageNum;
	Complex result;
	realNum = real + x.getReal();
	imageNum = image + x.getImage();
	result.assign(realNum, imageNum);
	return result;
}