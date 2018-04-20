//pg01.h
#ifndef __PG01_H__
#define __PG01_H__
#include <iostream>
using namespace std;

enum TLGC {L0, L1, LX};

class CVec {

private:
  TLGC *vec;				//array in 3-valued logic
  int size;					//size of the array

public:
  //Q1: Basics 
  CVec();					//size=0
  CVec(int);				//the set contains only one CCplx object
  CVec(int, TLGC*);		
  CVec(const CVec&);		//copy from another COrdSet object
  ~CVec();					//desctroy the list if not empty
  int getSize()  const   ;            //return the size of the COrdSet object
  TLGC* getVec() const   ;
  void Print()  const   ; 
 
  //Q2: trancount and overload operator (!)	

  //Q3: overload operators ( & and |)

  //Q4: overload operators (+ and <<)


};

#endif
