// Complex.cpp
#include <iostream>
#include "Complex.h"
using namespace std;
// Member-function definitions for class Complex. 
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

Complex Complex::subtract(Complex x) {
	float realNum, imageNum;
	Complex result;
	realNum = real - x.getReal();
	imageNum = image - x.getImage();
	result.assign(realNum, imageNum);
	return result;
}

Complex Complex::multiply(Complex x) {
	float realNum, imageNum;
	Complex result;
	realNum = real * x.getReal() - image * x.getImage();
	imageNum = real * x.getImage() + image * x.getReal();
	result.assign(realNum, imageNum);
	return result;
}

Complex Complex::division(Complex x) {
	float realNum, imageNum;
	Complex result;
	realNum = (real * x.getReal() + image * x.getImage()) / (x.getReal() * x.getReal() - x.getImage() * x.getImage());
	imageNum = (image * x.getReal() - real * x.getImage()) / (x.getReal() * x.getReal() - x.getImage() * x.getImage());
	result.assign(realNum, imageNum);
	return result;
}