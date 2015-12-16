/*
  ex10-01.cc
    Sample source code for ex10-01
    This source code includes potential runtime errors. 
    Find them through test procedures and Fix the.
    Author: Yuta Sugii
    Date: 2015/12/16
 */

/*
  main()
    This program traslates lower characters into upper ones
    in a string given in a command line
 */

#define N 8

#include <iostream>
#include <cctype>
#include <string.h>

int main(int argc, char *argv[])
{
  //  String
  char str[N];
  //  Counter
  int i=1, len;
  
  //  Check the number of arguments and Abort if it is less than 2
  if(2 > argc){
    std::cerr << "uasage: ex10-01 string" << std::endl;
    std::cerr << "string must be less than eight characters" << std::endl;
    //  Abnormally terminated and return -1
    return(-1);
  }
  
   len = strlen( argv[1] );
   // std::cout << "len = " << len << std::endl;
   if(len > N)len = N; /* 入力文字数がNよりも大きい場合、最大出力文字数をNとする */

   // Translate each of characters to uppercase in the command line string and 
   // Store them in str and Output them
  for(i = 0; i < len; ++i){
    str[i] = toupper(argv[1][i]);
    std::cout << str[i];
  }
  std::cout << std::endl;

  //  Normally terminated and return 0
  return(0);
}

/*
元々のソースコードだと、８文字以下の入力を行うと入力した文字列に変な文字列が表示される。
実行結果
$ ./a.out abcdefgh
ABCDEFGH
$ ./a.out a
AMANPAT
$ ./a.out 1
1MANPAT

原因は初期化していなかったことが原因と思ったがそういうわけではなく、
ループの回数がN＝８と入力文字数に関係なく入力させたことが原因とわかった。
./a.out abc... 第１引数の文字数を得るためにstrlenを用意し、入力した文字数をlenに格納。
Nよりも大きい場合はlen=Nとし、表示するようにした。これにてex10-01.ccは完成。
*/
