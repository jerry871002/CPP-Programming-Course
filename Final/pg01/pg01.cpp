#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;
class Point2D
{
private:
	int x;
	int y;
	int id;
public:
	bool operator>(Point2D& p) {

	}

};

class WeightedPoint: public Point2D
{
private:
	int weight;
public:
	//..
};

int main(int argc,char* argv[])
{
    //read file 1 (t1a_coordinate.in)
    ifstream file1(argv[1]);

    //define the vector container here
    vector<Point2D> Point_vec;
    //ReadFile1(file1,Point_vec);

    //sort these points with x increasing order then with y increasing order
    //sort(Point_vec.begin(),Point_vec.end(),CompareFunction);

    //show the new order after sorting
    cout << "after sorting, the new order is : " << endl;


    //compute the distance through the path after sorting
    double distance;
    //distance = Distance_computation1(Point_vec);
    cout << "after sorting, the distance is : " << distance << endl;

    //read file 2 (t1a_weight.in)
    ifstream file2(argv[2]);
    //delete the points with lower weight among the points in the same coordinate x.
    //vector<WeightedPoint> Point_wvec;
    //ReadFile2(file2,Point_wvec,Point_vec);

    //show the new order after deletion
    cout << "after deletion, the new order is : " << endl;
    //...

    //compute the distance through the path after deletion
    //distance = Distance_computation2(Point_wvec);
    cout << "after deletion, the distance is : " << distance << endl;
    return 0;

}
