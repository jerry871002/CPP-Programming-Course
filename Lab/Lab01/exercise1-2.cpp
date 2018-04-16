//Works on c9(Ubuntu) but fail on local(macOS)

#include <iostream>

using namespace std;

typedef struct {
	double real;
	double image;
} Cplex;

Cplex complexOperation(Cplex, Cplex, char);
void printComplex(Cplex[]);
char positive(double);

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

Cplex complexOperation(Cplex numA, Cplex numB, char sign) {
	Cplex result;
	switch(sign) {
		case '+':
			result.real = numA.real + numB.real;
			result.image = numA.image + numB.image;
			return result;
		case '-':
			result.real = numA.real - numB.real;
			result.image = numA.image - numB.image;
			return result;
		case '*':
			result.real = numA.real * numB.real - numA.image * numB.image;
			result.image = numA.real * numB.image + numA.image * numB.real;
			return result;
		case '/':
			result.real = (numA.real * numB.real + numA.image * numB.image) / (numB.real * numB.real + numB.image * numB.image);
			result.image = (-1 * numA.real * numB.image + numA.image * numB.real) / (numB.real * numB.real + numB.image * numB.image);
			return result;
	}
}

void printComplex(Cplex imgNums[]) {
	cout << "==============================" << endl;
	cout << "The output results:" << endl;
	cout << "A + B = " << imgNums[0].real << positive(imgNums[0].image) << imgNums[0].image << 'i' << endl;
	cout << "A - B = " << imgNums[1].real << positive(imgNums[1].image) << imgNums[1].image << 'i' << endl;
	cout << "A * B = " << imgNums[2].real << positive(imgNums[2].image) << imgNums[2].image << 'i' << endl;
	cout << "A / B = " << imgNums[3].real << positive(imgNums[3].image) << imgNums[3].image << 'i' << endl;
}

char positive(double num) {
	if(num >= 0)
		return '+';
	else
		return '\0';
}