#include <iostream>
#include <fstream>

using namespace std;

int count(string);
void printWorlds(string);

int main(int argc, char *argv[]) {
	ifstream in_file;
	in_file.open(argv[1]);
	string inputStr;
	int lineCnt = 1;
	while(getline(in_file, inputStr)) {
		int worldsCnt = count(inputStr);
		cout << "line " << lineCnt << " has " << worldsCnt << " worlds, ";
		printWorlds(inputStr);
		lineCnt++;
	}
	return 0;
}

int count(string str) {
	int position1, position2 = -1, cnt = 0;
	while(1) {
		position1 = str.find(" ",position2+1);
		if(position1 == -1) 
			break;
		position2 = position1;
		cnt++;
	}
	return (cnt+1);
}

void printWorlds(string str) {
	int position1, position2 = -1;
	while(1) {
		position1 = str.find(" ",position2+1);
		cout << "\"" << str.substr(position2+1, position1-position2-1) << "\" ";
		if(position1 == -1) 
			break;
		position2 = position1;
	}
	cout << endl;
}