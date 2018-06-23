#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Pair
{
public:
	Pair();
	Pair(int count, int score){
	    //...
	};
	int getc(){ return c;}
	int gets(){ return s;}
	friend ostream& operator<<(ostream& out, Pair &p);
private:
	int c;
	int s;
};

int main(int argc, char *argv[])
{
   	ifstream inFile(argv[1]);
	int a, b;
	inFile >> a >> b;
	for(int i = 1; i <= a; i++) {
		string name;
		int score;
		inFile >> name >> score;
		cout << name << " " << i << " " << score << endl;
	}
	return 0;
}
