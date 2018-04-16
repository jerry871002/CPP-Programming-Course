// HugeInteger.h
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
class HugeInteger
{
public:
	// put your member function prototype
	HugeInteger();
	HugeInteger(string);
	HugeInteger(int);
	HugeInteger(HugeInteger&);
	void output();
	HugeInteger add(HugeInteger&);
	HugeInteger subtract(HugeInteger&);
	bool isEqualTo(HugeInteger&);
	bool isNotEqualTo(HugeInteger&);
	bool isLessThan(HugeInteger&);
private:
	int *data;
	int length;
}
#endif 