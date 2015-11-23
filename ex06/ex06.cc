/*
  Filename: ex06.cc
  Outline: 文章を単語ごとに入力し、その単語の出現回数をアルファベット順に出力する
  Author: Yuta Sugii
  Student ID: s1220135
  Date: 2015-11-10
*/
#include<iostream>
#include<string>
#include<ctype.h>
#include<algorithm>
#include<iterator>
#include<vector>
 
//名前空間の宣言
using namespace std;
 
//構造体の定義
struct WordCount{
  string Word;
  int Count;
};
 
struct URL{
  string pro;
  string dom;
};
 
//平均外部変数の宣言
double ave;
 
//関数の宣言
string low(string);
bool isAlphaWord(const WordCount&);
bool isAboveAverage(const WordCount&);
 
 
int main(){
  vector<WordCount>words,alpha_words;
  vector<URL>urls; //URLを要素とするvector型の変数に記録
  URL url;
  WordCount g;
  string s;
  vector<WordCount>::iterator iter,iter2,iter3;
 
  while(cin >> s){
    if(s.size() != 1)
      s = low(s);
    int isFound = 0;
    iter = words.begin();
 
    while(iter != words.end()){
      //sがwordsのどれかの要素と同じ��豺�
      if((*iter).Word == s){
    isFound = 1;
    ++(*iter).Count;
    break;
      }
      ++iter;
    }
 
    //sがwordsの要素に含まれていなければ、追加する
    if(isFound == 0){
      g.Word = s;
      g.Count = 1;
      words.push_back(g);
    }
  }
   
  //アルファベットのみの単語とそう瘢雹でないものをわける
  iter2 = stable_partition(words.begin(), words.end(), isAlphaWord);
   
  //アルファベットのみからなる単語の平均出現頻度を求める
  iter = words.begin();
  int k = 0;
  while(iter != iter2){
    ave += (*iter).Count;
    ++iter;
    ++k;
  }
  ave = ave/k;
 
  //単語の出現頻度が平均よりも高いかどう瘢雹か判定, iter3は境目になる
  iter3 = stable_partition(words.begin(), iter2, isAboveAverage);
 
  //URLかどう瘢雹かの判定
  vector<WordCount>::iterator ur  = iter2;
  string::iterator iter_s;
  string sep = "://";
  while(ur != words.end()){
    URL url;
    //
    iter_s = search((*ur).Word.begin(), (*ur).Word.end(), sep.begin(), sep.end());
    if(iter_s != (*ur).Word.end()){
      //もしもURLだった��豺�,urlという瘢雹構造体にコピ・踉擦垢�
      copy((*ur).Word.begin(), iter_s, back_inserter(url.pro));
      copy(iter_s+3, (*ur).Word.end(), back_inserter(url.dom));
      //urlの中身をurlsという瘢雹配列にコピ・踉擦垢�
      urls.push_back(url);
      words.erase(ur);
    }
    else ++ur;
  }
   
  iter = words.begin();
  cout << "*** Alpha Words Above Average(" << ave << ") ***" << endl;
  while(iter != iter3){
    string space(25 - (*iter).Word.size(),' ');
    cout << (*iter).Word << space << (*iter).Count << endl;
    ++iter;
  }
 
  cout << "*** Alpha Words Below Average(" << ave << ") ***" << endl;
  while(iter != iter2){
    string space(25 - (*iter).Word.size(),' ');
    cout << (*iter).Word << space << (*iter).Count << endl;
    ++iter;
  }   
 
  //URL以外の記号を含んだ単語を出力
  cout << "*** Other Words" << endl;
  while(iter != words.end()){
    string space(40 - (*iter).Word.size(),' ');
    cout << (*iter).Word << space << (*iter).Count << endl;
    ++iter;
  }   
 
  //URLを出力
  cout << "URL" << endl;
  vector<URL>::iterator iter_u = urls.begin();
  while(iter_u != urls.end()){
    cout << (*iter_u).pro << "                " << (*iter_u).dom << endl;
    ++iter_u;
  }
}
 
 
//アルファベットについている記号を��覆①�臺源悊鬢苳皿文字にする
string low(string s){
  //isalnum()はアルファベットか数字なら、trueを返す関数
  while(!isalnum(s[0])){
    s = s.substr(1, s.size() -1);
  }
  while(!isalnum(s[s.size()-1])){
    if(s[s.size() - 1] != '+' && s != "etc.")
      s = s.substr(0, s.size() - 1);
    else break;
  }
 
  for(string::size_type i = 0; i != s.size(); ++i){
    s[i]= tolower(s[i]);
  }
  return s;
}
 
 
//文字列が記号かどう瘢雹か判断する
bool isAlphaWord(const WordCount& w){
  for(string::size_type i = 0; i != w.Word.size(); i++){
    if(!isalpha(w.Word[i])) return false;
  }
  return true;
}
 
//出現頻度が平均よりも高いかどう瘢雹か判別する
bool isAboveAverage(const WordCount& w){
  if(w.Count > ave) return true;
  else return false;
}
 
