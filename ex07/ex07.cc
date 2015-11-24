#include<vector>
#include<string>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<iterator>
#include<map>
 
//ネームスペースの宣言 
using namespace std;
 
//関数のプロトタイプ宣言
vector<string> split( const string& );
bool space( char );
bool not_space( char );
 
int main(){
  //変数の宣言
  map< string, vector<int> > counters;
  vector<string> words;
  string grep, s, tmp;
  int line_num = 0; //行番号を保存する変数
 
  getline( cin, grep );
   
  while( getline( cin, s ) ) {
 
    //行番号＋１
    ++line_num;
 
    //行を単語に分解
    words = split( s );
 
    vector<string>::iterator it = words.begin();
 
    while( it != words.end() ){
       
      tmp = *it;

      for( string::size_type i = 0 ; i != tmp.size() ; ++i ) {
        tmp[i] = tolower( tmp[i] );
      }
       
      //最初の文字が記号ならば削る
      if( tmp.size() > 1 ) {
    if( !isalnum( tmp[ 0 ] ) ) {
      tmp = tmp.substr( 1, tmp.size() - 1 );
    }
      }
       
      //最後の文字が記号(+除く)ならば削る 
      if( tmp.size() > 1 ) {
    if( !isalnum( s[ tmp.size() - 1 ]) && tmp[ tmp.size() - 1 ] != '+' ) {
       
      tmp = tmp.substr( 0, tmp.size() - 1 );
       
      if( !isalnum( tmp[ tmp.size() - 1 ]) && 
          tmp[ tmp.size() - 1 ] != '+' && 
          tmp[ tmp.size() - 1 ] != '.' ) {
         
        tmp = tmp.substr( 0, tmp.size() - 1 );
         
      }
    }
      }
      counters[ tmp ].push_back( line_num );
      ++it;
    }
  }
 
  //出力
  vector<int>::const_iterator it = counters[ grep ].begin();
  cout << grep << " is appeared at ";
  cout << *it;
  ++it;
  while( it != counters[ grep ].end() ){
    cout << " " << *it;
    ++it;
  }
  cout << endl;
  return 0;
   
}
 
//単語に分解する関数
vector<string> split( const string& str ) {
 
  typedef string::const_iterator iter;
  vector<string> ret;
 
  iter i = str.begin();
 
  while( i != str.end() ){
 
    //はじめに空白があればそれらは無視する
    i = find_if( i, str.end(), not_space );
 
    iter j = find_if( i, str.end(), space );
 
    //[i, j)の範囲の文字をコピ-
    if( i != str.end() ) {
      ret.push_back( string( i, j ) );
    }
 
    i = j;
  }
  return ret;
}
 
//スペースが入っているかどうかの判別を行う
bool space( char c ){ return  isspace( c ); }
bool not_space( char c ){ return !isspace( c ); }
 