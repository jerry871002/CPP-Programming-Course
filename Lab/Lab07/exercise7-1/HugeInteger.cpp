// HugeInteger.cpp
#include <iostream>
#include <string>
#include "HugeInteger.h"

using namespace std;
// Member-function definitions for class HugeInteger.

HugeInteger::HugeInteger() {
	data = new int[40];
	for(int i = 0; i < 40; i++)
		data[i] = 0;

	length = 0;
}

HugeInteger::HugeInteger(string num) {
	data = new int[40];
	for(int i = 0; i < 40; i++)
		data[i] = 0;

	length = num.length();
	long long x = stoll(num);
	for(int i = 0; i < length; i++) {
		data[i] = x % 10;
		x /= 10;
	}
}

HugeInteger::HugeInteger(int num) {
	data = new int[40];
	for(int i = 0; i < 40; i++)
		data[i] = 0;

	length = 0;
	int i = 0;
	do {
		data[i] = num % 10;
		i++;
		length++;
	} while((num /= 10) != 0);

}

HugeInteger::HugeInteger(HugeInteger& source) {
	length = source.length;
	data = new int[40];
	for(int i = 0; i < 40; i++)
		data[i] = source.data[i];
}

// const return avoids: ( a1 = a2 ) = a3
const HugeInteger& HugeInteger::operator=(const HugeInteger& right) {
	this->length = right.length;
	for(int i = 0; i < 40; i++)
		this->data[i] = right.data[i];

	return (*this); // enable x = y = z;
}

void HugeInteger::output() {
	for(int i = length - 1; i >= 0; i--)
		cout << data[i];
}

ostream& operator<<(ostream& out, HugeInteger num) {
	for(int i = num.length - 1; i >= 0; i--)
		out << num.data[i];
	return out;
}

HugeInteger HugeInteger::add(HugeInteger& addend) {
	HugeInteger result;

	int carry = 0;
	for(int i = 0; i < 40; i++) {
		result.data[i] = data[i] + addend.data[i] + carry;
		if(result.data[i] > 9) {
			carry = 1;
			result.data[i] -= 10;
		} else
			carry = 0;
	}

	result.length = 1;
	for(int i = 39; i > 0; i--) {
		if(result.data[i] > 0){
			result.length = i + 1;
			break;
		}
	}

	return result;
}

HugeInteger HugeInteger::subtract(HugeInteger& divisor) {
	HugeInteger result;
	int borrow = 0;
	for(int i = 0; i < 40; i++) {
		result.data[i] = data[i] - divisor.data[i] - borrow;
		if(result.data[i] < 0) {
			borrow = 1, 
        	result.data[i] += 10;
		} else
            borrow = 0;
	}

	result.length = 1;
	for(int i = 39; i > 0; i--) {
		if(result.data[i] > 0){
			result.length = i + 1;
			break;
		}
	}

	return result;
}

bool HugeInteger::isEqualTo(HugeInteger& numToCompare) {
	if(length != numToCompare.length)
		return false;
	for(int i = 0; i < length; i++) {
		if(data[i] != numToCompare.data[i])
			return false;
	}
	return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger& numToCompare) {
	return !isEqualTo(numToCompare);
}

bool HugeInteger::isLessThan(HugeInteger& numToCompare) {
	if(length > numToCompare.length)
		return false;
	else if(length < numToCompare.length)
		return true;
	else {
		for(int i = 0; i < length; i++) {
			if(data[i] > numToCompare.data[i])
				return false;
		}
		return true;
	}
}
