#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "Date.h"

using namespace std;

string monthString[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int days[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t seconds = time(NULL);
	struct tm* t = localtime(&seconds);
	month = t->tm_mon + 1;
	day = t->tm_mday;
	year = t->tm_year + 1900;
}

Date::Date(int d, int y) {
	year = y;
	for(int i = 0; i < 12; i++) {
		if(d > daysInMonth(i+1))
			d -= daysInMonth(i+1);
		else {
			month = i + 1;
			day = d;
			break;
		}
	}
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	setYYYYFromYY(y);
}

Date::Date(string m, int d, int y) {
	month = setMMFromMonth(m);
	day = d;
	year = y;
}

void Date::setDay(int d) {
	day = d;
}

void Date::setMonth(int m) {
	month = m;
}

void Date::print() const {
	cout << month << "/" << day << "/" << year << endl;
}

void Date::printDDDYYYY() const{
	cout << convertDDToDDD() << " " << year << endl;
}

void Date::printMMDDYY() const {
	cout << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "/" << setw(2) << setfill('0') << convertYYYYToYY() << endl; 
}

void Date::printMonthDDYYYY() const {
	cout << convertMMToMonth(month) << " " << day << ", " << year << endl;
}

Date::~Date() {
	cout << "Date object destructor for date ";
	print();
}

//private
//int Date::checkDay( int ) const

int Date::daysInMonth(int m) const {
	days[1] = isLeapYear() ? 29 : 28;
	return days[m-1];
}

bool Date::isLeapYear() const {
	bool isLeap = false;
	if(year % 4 == 0)
		isLeap = true;
	if(year % 100 == 0)
		isLeap = false;
	if(year % 400 == 0)
		isLeap = true;
	return isLeap;
}

int Date::convertDDToDDD() const {
	int result = 0;
	for(int i = 0; i < month - 1; i++)
		result += daysInMonth(i+1);
	result += day;
	return result;
}

//void Date::setMMDDFromDDD( int )

string Date::convertMMToMonth(int m) const {
	return monthString[m-1];
}

int Date::setMMFromMonth(string m) {
	for(int i = 0; i < 12; i++) {
		if(m.compare(monthString[i]) == 0)
			return i + 1;
	}
}

int Date::convertYYYYToYY() const {
	return year % 100;
}

void Date::setYYYYFromYY(int y) {
	if(y < 30)
		year = 2000 + y;
	else
		year = 1900 + y;
}