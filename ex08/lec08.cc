/*
標準入力した単語の奇数個目の文字と偶数個目の文字が入れ替わるプログラム
*/

#include <list>
#include <iostream>
#include <string>

using namespace std;

template <class Type>
void swap(Type &a, Type &b)
{
	Type temp = a;

	a = b;
	b =temp;
}

int main()
{
	list<string> words;
	string str;

	while(cin >> str){
		words.push_back(str);
	}

	list<string>::iterator i = words.begin();

	for(i=words.begin(); i != words.end(); ++i){
		swap(*i, *(++i));
		if(i==words.end())
			break;
	}

	// for(the_iterator = word.begin(); the_iterator != word.end(); the_iterator+=2, i+=2)
	// 	swap(word[i-1], word[i]);
	// for(the_iterator = word.begin(); the_iterator != word.end(); the_iterator++, i++)
	// 	cout << word[i] << endl;

	for(i=words.begin(); i!=words.end(); ++i){
		cout << *i << ' ';
	}

	cout << endl;

	return 0;
}

/*
実行結果

$ ./a.out
I am your father
am I father your

となる。
*/
