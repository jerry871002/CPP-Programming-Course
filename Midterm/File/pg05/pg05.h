//pg05.h
#ifndef _PG05_H_
#define _PG05_H_
#include <iostream>

using namespace std; 

class BigInt {
private:
    int *arr;
public:
    BigInt();
    BigInt(int n);
    ~BigInt() {
        delete[] arr;
    }
    BigInt& operator =(const BigInt& ) ;
    BigInt operator +(const BigInt &) const;
    void print() const ;
};


#endif