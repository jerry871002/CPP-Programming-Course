#ifndef MATRIX_H
#define MATRIX_H
/* Write class definition for Matrix and add constructors and destructor*/
class Matrix{
private:
	int dim; //n*n size matrix
	int *matrix;
public:
	Matrix();
	Matrix(int);
	~Matrix();
	Matrix(const Matrix&);
	void assignElements();
	void printMatrix();
	void transposeMatrix();
	void multiplyMatrix(Matrix, Matrix);
};
#endif