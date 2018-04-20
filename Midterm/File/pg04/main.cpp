#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "pg01.h"
using namespace std;

int main(int argc, char ** argv) {
	srand(1);
	if (argc<2) {
		cout << "[Error] Do not forget to specify the question id (1-4)!!" << endl;
		return -1;
	}
	cout << endl;
	int tid(atoi(argv[1]));	
	
	TLGC m[4] = {LX,L1,L0,LX};
	CVec a(2), b(5);
	const CVec c(4,m);
	CVec *px(&b), *py;
	py = new CVec(c);

if (tid==1) {
	//Q1
	cout << "[Q1]" << endl;
	cout << "  ( a) " << a.getSize() << " " << a.getVec() << " "; a.Print(); cout << endl;	
	cout << "  ( b) " << b.getSize() << " " << b.getVec() << " "; b.Print(); cout << endl;	
	cout << "  ( c) " << c.getSize() << " " << c.getVec() << " "; c.Print(); cout << endl;	
	cout << "  (px) " << px->getSize() << " " << px->getVec() << " "; px->Print(); cout << endl;	
	cout << "  (py) " << py->getSize() << " " << py->getVec() << " "; py->Print(); cout << endl;	
} /*else if (tid==2) {
	//Q2	
	cout << "[Q2]" << endl;
	const CVec d(15);
	cout << "  ( d) "; d.Print(); 
	cout << " w/ tran#=" << d.trancount() << endl;
	cout << "  (!d) "; (!d).Print();	
	cout << " w/ tran#=" << (!d).trancount() << endl;
} else if (tid==3) {
	//Q3
	cout << "[Q3]" << endl;
	CVec  p(5), q(4);  
	const CVec& e = b & p;//
	cout << "  ( e) "; b.Print(); cout << "&"; p.Print(); cout << "="; e.Print(); cout << endl; 
    CVec * pf = new CVec(c | q); 
	cout << "  (pf) "; c.Print(); cout << "|"; q.Print(); cout << "="; pf->Print(); cout << endl; 
} else if (tid==4) {
	//Q4
	cout << "[Q4]" << endl;
	const CVec &g = b+c+a;
	cout << "  ( g) " << b << "+" << c << "+" << a << "=" << g << endl; 
	CVec h=(c+px);
	cout << "  ( h) " << c << "+" << (*px) << "=" << h << endl;
} else ;
	cout << endl;*/
	return 0;
}
