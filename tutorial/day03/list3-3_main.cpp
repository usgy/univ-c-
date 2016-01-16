#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    s = "This is a"; // 最初の文字列
    s.append(" pen."); // 文字列の追加
    cout << s << endl;
    cout << "文字列の長さ: " << s.length() << endl;
    // printfで表示
    printf("char*: %s\n", s.c_str());
    return 0;
}

