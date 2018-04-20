#include <fstream>
#include "pg01.h"
using namespace std;

int main(int argc, char *argv[])
{
	ifstream infile(argv[1]);
    Box box = ReadFile(infile);
    box.printVolume();
    box.printMinSide();
    box.printMaxSide();

    return 0;
}