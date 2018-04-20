#include "pg05.h"

int main() {
	int n;
    BigInt fn_2(0), fn_1(1), fn;
    cin >> n;
    
    for (int i = 2; i < n; i++){
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    fn.print();
    return 0;
}