#include <iostream>
#include "prob3-1_data.h"

using namespace std;

int main(){
    CData d;
    d.init(); //パラメータを初期化
    d.setNumber(100);
    d.setComment("Programming C++");
    cout << "number = " << d.getNumber() << " comment = " << d.getComment() << endl;
    return 0;
}
