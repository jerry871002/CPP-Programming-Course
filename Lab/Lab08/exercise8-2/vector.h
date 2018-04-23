#include <iostream>

using namespace std;

template <class T>
class Vector;
class Point2D;

template <class T>
class Vector {
private:
	int len;
	T* vec;
public:
	Vector(int n, double x) {
		len = n;
		vec = new T[n];
		for(int i = 0; i < len; i++)
			vec[i] = x;
	}

	Vector(int n, T *x) {
		len = n;
		vec = x;
	}

	void display() {
		for(int i = 0; i < len; i++)
			cout << vec[i] << " ";
		cout << endl;
	}

	template<class S>
	Vector<S> & operator+=(const Vector<S> &addend) {
		for(int i = 0; i < len; i++)
			vec[i] += addend.vec[i];
		return (*this);
	}

	template<class S>
	friend S dot(const Vector<S> &, const Vector<S> &);
};

template<class T>
T dot(const Vector<T> &a, const Vector<T> &b) {
	T result;
	result = 0;
	for(int i = 0; i < a.len; i++)
		result += (a.vec[i] * b.vec[i]);
	return result;
}

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

	int getX() const {return x;}
	int getY() const {return y;}

	Point2D& operator+=(const Point2D& aDot) {
		x += aDot.x;
		y += aDot.y;
		return (*this);
	}

	Point2D operator*(const Point2D& aDot) {
		Point2D result;
		result.setCor(x * aDot.x, y * aDot.y);
		return result;
	}

	void operator=(double num) {
		x = (int)num;
		y = (int)num;
	}
	
	friend ostream& operator<<(ostream&, const Point2D&);
};

template<class T>
void rand1D(T *vec, int n) {
	for(int i = 0; i < n; i++)
		vec[i].setCor(rand() % 10, rand() % 10);
}

ostream& operator<<(ostream& out, const Point2D& dot) {
	out << "(" << dot.getX() << " , " << dot.getY() << ")";
	return out;
}