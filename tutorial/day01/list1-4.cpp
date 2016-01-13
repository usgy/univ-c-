#include <iostream>
#include <string>

using namespace std;

int main() {
    string s,t;
    t = "入力された文字は、";
    cout << "文字列を入力:" ;
    cin >> s;
    cout << t+s << "です。" << endl;
    return 0;
}

