// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
class Complex {
private:
	float real;
	float image;
public:
	void printComplex();
	void assign(float, float);
	void assignReal(float);
	void assignImage(float);
	float getReal();
	float getImage();
	Complex add(Complex);
	Complex subtract(Complex);
	Complex multiply(Complex);
	Complex division(Complex);
};
#endif