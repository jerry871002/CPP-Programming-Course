//pg01.h
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef __PG01_H__
#define __PG01_H__
class Box {
public:
	Box(double length = 0, double width = 0, double height = 0) {
		l = length;
		w = width;
		h = height;
	}

	void printVolume() {
		double volume;
		volume = l * w * h;
		cout << "The volume is " << fixed  <<  setprecision(2) << volume << endl;
	}

    void printMinSide() {
    	double min = l;
    	if(w < min)
    		min = w;
    	if(h < min)
    		min = h;
    	cout << "The Max Side is " << fixed  <<  setprecision(2) << min << endl;
    }

    void printMaxSide() {
    	double max = l;
    	if(w > max)
    		max = w;
    	if(h > max)
    		max = h;
    	cout << "The Max Side is " << fixed  <<  setprecision(2) << max << endl;
    }

    friend Box ReadFile(ifstream& inFile);

private:
	double l, w, h;
};

Box ReadFile(ifstream& inFile) {
    double length, width, height;
    inFile >> length >> width >> height;
    return Box(length, width, height);
}

#endif
