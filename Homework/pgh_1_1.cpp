#include <iostream>
using namespace std;

template <class T>
void findMax(T, T, T);

int main()
{
    findMax(3, 7, -5);
    findMax(2.8, 3.9, 1.8);
    
    return 0;
}

template <class T>
void findMax(T a, T b, T c) {
	T max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	cout << max << endl;
}