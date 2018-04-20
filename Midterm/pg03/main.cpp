#include"pg03.h"

int main()
{
    // two dimensional points
    Line a(2);
    
    // cordinates of two points
    double point11[2] = {0,0}, point12[2] = {3,4};
    
    // set the cordinates
    a.setPoint(point11, point12);
   
    // calculate the distance and print it out
    a.calDist();
    a.printDist();
    
    // three dimensional points
    Line b(3);
    
    // cordinates of two points
    double point21[3] = {0,0,0}, point22[3] = {3,4,5};
    
    // set the cordinates
    b.setPoint(point21, point22);
    
    // calculate the distance and print it out
    b.calDist();
    b.printDist();
 
    return 0;
}