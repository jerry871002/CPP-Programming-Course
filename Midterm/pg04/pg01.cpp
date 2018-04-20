//pg01.cpp //start your code below
#include "pg01.h"
#include <stdlib.h> 
#include <iostream>

CVec::CVec() {
	size = 0;
	vec = NULL;
}
CVec::CVec(int numOfElements) {
	size = numOfElements;
	vec = new TLGC[numOfElements];
	for(int i = 0; i < numOfElements; i++) {
		vec[i] = (TLGC)(rand() % 3);
	}
}

CVec::CVec(int numOfElements, TLGC* tired) {
	size = numOfElements;
	vec = new TLGC[numOfElements];
	for(int i = 0; i < numOfElements; i++) {
		vec[i] = tired[i];
	}
}

CVec::CVec(const CVec& veryTired) {
	size = veryTired.size;
	vec = new TLGC[size];
	for(int i = 0; i < size; i++) {
		vec[i] = veryTired.vec[i];
	}
}

CVec::~CVec() {
	if(vec != NULL && size != 0)
		delete[] vec;
}

int CVec::getSize() const {
	return size;
}

TLGC* CVec::getVec() const {
	return vec;
}
void CVec::Print() const {
	for(int i = 0; i < size; i++) {
		std::cout << (TLGC)vec[i];
	}
}
