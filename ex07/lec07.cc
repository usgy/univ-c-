/*
文字列は氏名をキー、文字列型の電話番号を値とする連想記憶phonebookを持ち、その内容は"John"の電話番号が”555-0000”、”Paul”は”555-1111”、”Ringo”の電話番号が”555-2222”、”George”の電話番号が”555-3333”とする
　このとき、標準入力ストリームcinから氏名を入力し、対応する電話番号を入力し、その後にphonebookに含まれるすべての氏名と電話番号を標準出力ストリームに出力するプログラムを書け
*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

int main(){
	map<string, string> phonebook;
	string s;
	while(cin >> s){
		++ phonebook[s];
	}
	for(map <string, string>::iterator iter = phonebook.begin(); iter!=phonebook.end(); ++iter){
		cout << iter -> first << "¥t" << iter -> second << endl;
	}

	return 0;
}