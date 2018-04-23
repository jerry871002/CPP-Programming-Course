#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Point2D
{
private:
	int x;
	int y;
public:
	void setCor(int a, int b) {
		x = a;
		y = b;
	}
	int getX() {return x;}
	int getY() {return y;}
};

template<class T>
T *new1D(int n, int k) {
	T *vec = new T[n];
	for (int i = 0; i < n; i++)
		vec[i] = k;
	return vec;
}

template<>
Point2D *new1D(int n, int k) {
	Point2D *vec = new Point2D[n];
	for(int i = 0; i < n; i++)
		vec[i].setCor(k, k);
	return vec;
}

template<class T>
void rand1D(T *vec, int n) {
	for(int i = 0; i < n; i++)
		vec[i] = rand() % 10 + 1;
}

template<>
void rand1D(double *vec, int n) {
	for(int i = 0; i < n; i++)
		vec[i] = (rand() % 1001) * 0.01;
}

template<>
void rand1D(char *vec, int n) {
	for(int i = 0; i < n; i++)
		vec[i] = (char)((rand() % 26) + 97);
}

template<>
void rand1D(Point2D *vec, int n) {
	for(int i = 0; i < n; i++)
		vec[i].setCor(rand() % 10, rand() % 10);
}

template<class T>
void display1D(T *vec, int n) {
	for(int i = 0; i < n; i++)
		cout << vec[i] << " ";
	cout << endl;
}

template<>
void display1D(Point2D *vec, int n) {
	for(int i = 0; i < n; i++)
		cout << "(" << vec[i].getX() << " , " << vec[i].getY() << ") ";
	cout << endl;
}

template<class T>
void sort1D(T *vec, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(vec[j] > vec[j+1]) {
				T temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}

template<>
void sort1D(Point2D *vec, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(vec[j].getX() > vec[j+1].getX()) {
				Point2D temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			} else if(vec[j].getX() == vec[j+1].getX()) {
				if(vec[j].getY() > vec[j+1].getY()) {
					Point2D temp = vec[j];
					vec[j] = vec[j+1];
					vec[j+1] = temp;
				}
			}
		}
	}
}

template<class T>
void analysis(int n, int k = 0) {
	T *vec = new1D<T> (n, k);
	rand1D<T>(vec,n);
	// for int 1~10, for double 0.00~10.00, for char a~z,
	// for Point2D x: 0~9 y:0~9
	display1D<T>(vec,n);
	sort1D<T>(vec,n);
	display1D<T>(vec,n);
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	srand(1);
	analysis<int>(n);
	analysis<double>(n);
	analysis<char>(n);
	analysis<Point2D>(n);
	return 0;
}