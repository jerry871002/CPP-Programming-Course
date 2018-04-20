//practice file I/O

#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream inFile("in.txt");
	ofstream outFile("out.txt");

	int numOfElemnts, value, sum = 0;
	inFile >> numOfElemnts;
	for(int i = 0; i < numOfElemnts; i++) {
		inFile >> value;
		sum += value;
	}

	outFile << "The average is: " << (float)sum / numOfElemnts;

	inFile.close();
	outFile.close();

	return 0;
}