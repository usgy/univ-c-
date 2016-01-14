#include <iostream>
#include "list2-1.h"

using namespace std;

int main()
{
    CSample obj; // CSampleをインスタント化
    int num;

    cout << "整数を入力して下さい" << endl;
    cin >> num;

    obj.set(num); // CSampleのメンバ変数をセット
    cout << obj.get() << endl; // メンバ変数の値を出力

    return 0;
}

