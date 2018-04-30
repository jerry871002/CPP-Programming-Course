#include <iostream> #include <fstream> #include <vector> #include <algorithm> using namespace std;
class Complex{ ...
};
bool operator < (const Complex& a,const Complex& b) {
... }
void ReadFile(ifstream& infile, vector<Complex>& vec) { ...
}
int main(int argc, char** argv) {
	if(argc != 2) return 0; ifstream infile(argv[1]); if(!infile.is_open()) {
cout << "can not oepn file " << endl;
return 0; }
vector<Complex> vec; ReadFile(infile, vec);
cout << "Original sequence:" << endl; for(size_t i = 0; i< vec.size(); i++)
cout << vec[i] <<" "; cout << endl;
sort(vec.begin(),vec.end());
cout << "Sorted sequence:" << endl; for(size_t i = 0; i< vec.size(); i++)
cout << vec[i] <<" "; cout << endl;
return 0; }