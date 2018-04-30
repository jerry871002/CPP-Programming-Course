#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 

using namespace std;

class Complex{ 
public:
	Complex(float numX = 0, float numY = 0) : x(numX), y(numY) {
		//empty
	}

	float x, y;
};

bool operator < (const Complex& a, const Complex& b) {
	if(a.x > b.x)
		return true;
	else if(a.x == b.x && a.y > b.y)
		return true;
	else
		return false;
}

void ReadFile(ifstream& infile, vector<Complex>& vec) { 
	for(int i = 0; i < 5; i++) {
		float numX, numY;
		infile >> numX >> numY;
		cout << "#" << numX << " #" << numY << endl;
		Complex temp(numX, numY);
		vec.push_back(temp);
	}	
}

ostream& operator << (ostream& out, const Complex& a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

int main(int argc, char** argv) {
	if(argc != 2) 
		return 0;

	ifstream infile(argv[1]); 
	if(!infile.is_open()) {
		cout << "can not oepn file " << endl;
		return 0; 
	}

	vector<Complex> vec; 
	ReadFile(infile, vec);

	cout << "Original sequence:" << endl; 
	for(size_t i = 0; i< vec.size(); i++)
		cout << vec[i] << " "; 
	cout << endl;
	sort(vec.begin(),vec.end());

	cout << "Sorted sequence:" << endl; 
	for(size_t i = 0; i< vec.size(); i++)
		cout << vec[i] << " "; 
	cout << endl;

	return 0; 
}