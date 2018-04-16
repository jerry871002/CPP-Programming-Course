#include <iostream>

using namespace std;

typedef struct {
	char name;
	int* content;
	int row, col;	
} Matrix;

void printMatrix(Matrix);

int main() {
	int numOfMatrix, numOfFormula;
	char matrixName;
	int row, col;

	cin >> numOfMatrix;
	Matrix* matrix = new Matrix[numOfMatrix];
	for(int i = 0; i < numOfMatrix; i++) {
		cin >> matrixName >> row >> col;
		matrix[i].name = matrixName;
		matrix[i].content = new int[row*col];
		matrix[i].row = row;
		matrix[i].col = col;
		for(int j = 0; j < row * col; j++)
			cin >> matrix[i].content[j];
	}

	cin >> numOfFormula;
	for(int i = 0; i < numOfFormula; i++) {
		char matrixOne, matrixTwo, oper;
		int one, two;
		Matrix result;
		cin >> matrixOne >> oper >> matrixTwo;
		for(int i = 0; i < numOfMatrix; i++) {
			if(matrix[i].name == matrixOne)
				one = i;
			else if(matrix[i].name == matrixTwo)
				two = i;
		}
		switch(oper) {
			case '+':
				result.row = matrix[one].row;
				result.col = matrix[one].col;
				result.content = new int[result.row*result.col];
				for(int i = 0; i < result.row*result.col; i++)
					result.content[i] = matrix[one].content[i] + matrix[two].content[i];
				printMatrix(result);
				break;
			case '-':
				result.row = matrix[one].row;
				result.col = matrix[one].col;
				result.content = new int[result.row*result.col];
				for(int i = 0; i < result.row*result.col; i++)
					result.content[i] = matrix[one].content[i] - matrix[two].content[i];
				printMatrix(result);
				break;
			case '*':
				result.row = matrix[one].row;
				result.col = matrix[two].col;
				result.content = new int[result.row*result.col];
				for(int i = 0; i < result.row*result.col; i++)
					result.content[i] = 0;
				for(int i = 0; i < result.row; i++) {
					for(int j = 0; j < result.col; j++) {
						for(int k = 0; k < matrix[one].col; k++) {
							result.content[i*result.col+j] += matrix[one].content[i*matrix[one].col+k] * matrix[two].content[k*matrix[two].col+j];
						}
					}
				}
				printMatrix(result);
				break;
		}
	}
	return 0;
}

void printMatrix(Matrix X) {
	for(int i = 0; i < X.row; i++) {
		for(int j = 0; j < X.col; j++) {
			cout << X.content[i*X.col+j] << " ";
		}
		cout << endl;
	}
}