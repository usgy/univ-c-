/*
  Filename: ex05.cc
  Outline: 文章を単語ごとに入力し、その単語の出現回数をアルファベット順に出力する
  Author: Yuta Sugii
  Student ID: s1220135  
  Date: 2015-11-10
*/

#include <string>
#include <list>
#include <ctype.h>
#include <iostream>
#include <ios>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct WordCount{
  string word;
  int count;
};

bool compare( const WordCount&, const WordCount& );

int main(){
  string s;
  list<WordCount> words;  //WordCountという構造体をしたlist型の変数宣言
  WordCount wc;  //WordCount型として変数宣言

  //入力を行う
  while( cin >> s ){ 
    wc.word = "";  //初期化
    /* 記号であるかどうかの判別を行い、記号であれば保存をせず、文字であれば小文字で保存を行う */
    for( string::size_type i=0 ; i!=s.size() ; ++i ){
      if( (s[i] == ',')|| (s[i] == '.')||(s[i] == '\'')||(s[i] == '\"')||(s[i] == '(')||(s[i] == ')') ){
      	//string tmp = s.substr( 0, s.size()-1 );
      	continue; //記号はパスする
      }
      else wc.word += tolower( s[i] );  //文字である場合、小文字に変換をし、格納する
    }

    int isFound = 0; //一度格納した単語かどうかをカウントする
    list<WordCount>::iterator iter = words.begin();//イテレーターの宣言
    while( iter!=words.end() ){
      if( (*iter).word==wc.word ){ 
      	isFound = 1;
      	(*iter).count += 1; //カウントを増やす  
      	break;
      }
      ++iter;
    }
    if( isFound==0 ){   //保存したことのない単語の場合
      wc.count = 1;  //カウントを１にする
      words.push_back( wc );  //WordCount型のwcをWordCount型のwordsへ格納
    }
  }
  
  words.sort( compare ); //アルファベット順に格納を行う  
  
  //出力を行う
  list<WordCount>::iterator iter = words.begin();
  while( iter!=words.end() ){
    cout << setw(18) << left << (*iter).word;
    cout << (*iter).count << endl;
    ++iter;
  }
}


bool compare(const WordCount& x, const WordCount& y){
  //xとyのwordが異なるときはwordを比較する
    return  ( x.word < y.word );
}
