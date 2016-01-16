#include "list3-1_sample.h"
#include <iostream>

using namespace std;

void Sample::func1(){
    cout << "func1" << endl;
    a = 1;
    b = 1;
    func2();
}
void Sample::func2(){
    a = 2;
    b = 2;
    cout << "a=" << a << "," << "b=" << b << endl;
}

