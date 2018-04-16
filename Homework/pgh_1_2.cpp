#include <iostream>
#include <string>

using namespace std;

string whichYear(int);

int main() {
    string name, stdID, year;
    getline(cin, name, ',');
    getline(cin, stdID, ',');
    getline(cin, year);
    cout << "Hello, I am " << name << "." << endl;
    cout << "My student ID is " << stdID << "." << endl;
    cout << "This is my " << whichYear(stoi(year)) << " year in NCTU.";

    return 0;
}

string whichYear(int year) {
    switch(year) {
        case 1:
            return "first";
        case 2:
            return "second";
        case 3:
            return "third";
        case 4:
            return "fourth";
    }
}