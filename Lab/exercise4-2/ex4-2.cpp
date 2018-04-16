#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
#include "Matrix.h"
int main() {
	srand(time(NULL));
	int n;
	cout << "Enter n for n x n matrix: ";
	cin >> n;
	Matrix A(n), B(n); // create two Matrix objects
	A.assignElements(); // assign elements in Matrix A randomly
	cout << "A = ";
	A.printMatrix(); // output object A
	cout << endl;
	B.assignElements(); // assign elements in Matrix B randomly
	cout << "B = ";
	B.printMatrix(); // output object B
	cout << endl;
	Matrix tA(A); // use copy constructor to build tA
	cout << "tA= ";
	tA.transposeMatrix(); // transpose Matrix tA
	cout << endl;
	Matrix tB(B); // use copy constructor to build tB
	cout << "tB= ";
	tB.transposeMatrix(); // transpose Matrix tB
	cout << endl;
	Matrix C;
	C.multiplyMatrix(A, B); // C = A * B
	cout << "A * B = ";
	C.printMatrix(); // output object C
	cout << endl;
	return 0;
}