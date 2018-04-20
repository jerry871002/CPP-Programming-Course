#include "pg05.h"

BigInt::BigInt() {
	arr = new int[40];
	for(int i = 0; i < 40; i++)
		arr[i] = 0;

	arr[39] = 0;
}
BigInt::BigInt(int n) {	
	arr = new int[40];
	for(int i = 0; i < 40; i++)
		arr[i] = 0;
	
	arr[0] = n;

	arr[39] = 1;
}

BigInt& BigInt::operator =(const BigInt& someNum) {
	this->arr[39] = someNum.arr[39];
	for(int i = 0; i < 40; i++)
		this->arr[i] = someNum.arr[i];

	return (*this);
}

BigInt BigInt::operator +(const BigInt & someNum) const {
	BigInt result;

	int carry = 0;
	for(int i = 0; i < 40; i++) {
		result.arr[i] = arr[i] + someNum.arr[i] + carry;
		if(result.arr[i] > 9) {
			carry = 1;
			result.arr[i] -= 10;
		} else
			carry = 0;
	}

	result.arr[39] = 1;
	for(int i = 38; i > 0; i--) {
		if(result.arr[i] > 0){
			result.arr[39] = i + 1;
			break;
		}
	}

	return result;
}

void BigInt::print() const {
	for(int i = arr[39] - 1; i >= 0; i--)
		cout << arr[i];
	cout << endl;
}