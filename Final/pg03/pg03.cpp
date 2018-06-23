#include <iostream>
using namespace std;
//add quadruple class
template <class T1,class T2,class T3,class T4>
class quadruple {
public:
	T1 first;
	T2 second;
	T3 third;
	T4 fourth;
	quadruple() { ; }
	quadruple(T1 a, T2 b, T3 c, T4 d) : first(a), second(b), third(c), fourth(d) { ; }
};

template <class T1,class T2,class T3,class T4>
quadruple<T1, T2, T3, T4> make_quadruple(T1 a, T2 b, T3 c, T4 d) {
	quadruple<T1, T2, T3, T4> aQuad(a, b, c, d);
	return aQuad;
}

int main()
{
	quadruple<double,int,string,int> t1;
	quadruple<int,string,double,int> t2(1,"t2",0.01,3);
	t1 = make_quadruple<double ,int ,string, int>(0.03,3,"t1",4);
	cout << t1.first << " " << t1.second << " " << t1.third << " " << t1.fourth << endl;
	cout << t2.first << " " << t2.second << " " << t2.third << " " << t2.fourth << endl;
    return 0;
}
