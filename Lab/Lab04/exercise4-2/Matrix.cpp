#include <iostream>
#include "Matrix.h"

using namespace std;

// Member-function definitions for class Matrix.
Matrix::Matrix() {
	for(int i = 0; i < dim*dim; i++)
		matrix[i] = 0;
}

Matrix::Matrix(int d) {
	dim = d;
	matrix = new int[d*d];
}

Matrix::~Matrix() {
	delete[] matrix;
	matrix = NULL;
}

Matrix::Matrix(const Matrix& old) {
	dim = old.dim;
	matrix = new int[dim*dim];
	for(int i = 0; i < dim*dim; i++)
		matrix[i] = old.matrix[i];
}

void Matrix::assignElements() {
	for(int i = 0; i < dim*dim; i++) {
		matrix[i] = (rand() % 10 + 1);
	}
}

void Matrix::printMatrix() {
	cout << "[";
	for(int i = 0; i < dim; i++) {
		for(int j =0; j < dim; j++) {
			cout << matrix[i*dim+j] << " ";
		}
		if(i != dim - 1)
			cout << ";";
	}
	cout << "];";
}

void Matrix::transposeMatrix() {
	for(int i = 0; i < dim; i++) {
		for(int j =0; j < dim; j++) {
			if(i < j) {
				int temp = matrix[i*dim+j];
				matrix[i*dim+j] = matrix[j*dim+i];
				matrix[j*dim+i] = matrix[i*dim+j];
			}
		}
	}
	printMatrix();
}

void Matrix::multiplyMatrix(Matrix A, Matrix B) {
	if(A.dim != B.dim) {
		cout << "Can't multiply" << endl;
		exit(1);
	}
	dim = A.dim;
	matrix = new int[dim*dim];
	for(int i = 0; i < dim; i++) {
		for(int j=0; j < dim; j++) {
			for(int k=0; k < dim; k++) {
				matrix[i*dim+j] += A.matrix[i*dim+k] * B.matrix[k*dim+j];
			}
		}
	}
}