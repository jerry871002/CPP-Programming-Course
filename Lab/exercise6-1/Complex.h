// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
class Complex {
	friend void printMeg(Complex&, Complex&, char);
	friend void printComplex(Complex&);
	friend Complex operator-(Complex&);
private:
	float real;
	float image;
public:
	Complex();
	Complex(float, float);
	Complex operator+(Complex&);
	Complex operator-(Complex&);
	Complex operator*(Complex&);
	Complex operator/(Complex&);
	void setComplexNumber(float, float);	
};
#endif