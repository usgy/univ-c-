#include <iostream>
#include "prob2-1_keisan.h"

using namespace std;

int main(){
    Keisan k;
    k.a = 4;
    k.b = 3;
    cout << k.a << " + " << k.b << " = " << k.add() << endl;
    cout << k.a << " - " << k.b << " = " << k.sub() << endl;
    return 0;
}

