#include <iostream>

#define SIZE 10

using namespace std;

template <class X>
void bubbleSort(X[]);
template <class X>
void printNums(X[]);

int main() {
	int a[SIZE] = {2, 9, 10, 1, 7, 3, 4, 5, 8, 6 };
	double b[SIZE] = {2.2, 9.9, 10.1, 1.1, 7.7, 3.3, 4.4, 5.5, 8.8, 6.6};

	cout << "int data items in original order" << endl;
	printNums(a);
	bubbleSort(a);
	cout << "int data items in ascending order" << endl;
	printNums(a);

	cout << "float data items in original order" << endl;
	printNums(b);
	bubbleSort(b);
	cout << "float data items in ascending order" << endl;
	printNums(b);

	return 0;
}

template <class X>
void bubbleSort(X numbers[]) {
	X temp;

	for(int i = 0; i < SIZE-1; i++) {
		for(int j = 0; j < SIZE-i-1; j++) {
			if(numbers[j] > numbers[j+1]) {
				temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}
		}
	}
}

template <class X>
void printNums(X numbers[]) {
	for(int i = 0; i < SIZE; i++)
		cout << numbers[i] << " ";
	cout << "\n";
}