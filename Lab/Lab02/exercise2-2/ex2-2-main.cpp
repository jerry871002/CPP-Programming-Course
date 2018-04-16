// main function, client program

#include <iostream>
#include "ex2-2.h"

using namespace std;

int main(int argc, char *argv[])
{
	Cplex a, b;
	// promotes the user to input data
	char img;
	cout <<"First complex number: ";
	cin >> a.real >> a.image >> img;
	cout <<"Second complex number: ";
	cin >> b.real >> b.image >> img;
	// store the results of diff. operation
	Cplex results[4];
	results[0] = complexOperation(a, b, '+');
	results[1] = complexOperation(a, b, '-');
	results[2] = complexOperation(a, b, '*');
	results[3] = complexOperation(a, b, '/');

	printComplex(results);

	return 0;
} 