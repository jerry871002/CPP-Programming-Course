// HugeInteger.cpp
#include <iostream>
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

	length = num.length;
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
		data[i] = num % 10
		i++;
		length++;
	} while((num /= 10) != 0);

}

HugeInteger::HugeInteger(HugeInteger& source) {
	length = source.length;
	for(int i = 0; i < length; i++)
		data[i] = source.data[i];
}

void HugeInteger::output() {
	for(int i = length - 1; i >= 0; i--)
		cout << data[i];
}

HugeInteger HugeInteger::add(HugeInteger& addend) {
	HugeInteger result;
	result.length = ((length >= addend.length) ? length : addend.length);

	for(int i = 0; i < result.length; i++) {
		result.data[i] = data[i] + addend.data[i];
	}
	return result;
}
HugeInteger HugeInteger::subtract(HugeInteger& divisor);
bool HugeInteger::isEqualTo(HugeInteger& numToCompare) {
	if(length != numToCompare.length)
		return false;
	for(int i = 0; i < length; i++) {
		if(data[i] != numToCompare.data[i])
			return false
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
