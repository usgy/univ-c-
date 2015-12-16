/*
  ex10-02.cc
    Sample source code for ex10-02
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
  int i, len;
  
  //  Check the number of arguments and Abort if it is less than 2
  if(2 > argc){
    std::cerr << "uasage: ex10-02 string" << std::endl;
    std::cerr << "string must be less than eight characters" << std::endl;
    //  Abnormally terminated and return -1
    return(-1);
  }

  len = strlen( argv[1] );
  std::cout << "len = " << len << std::endl;
  if(len > N)len = N; /* 入力文字数がNよりも大きい場合、最大出力文字数をNとする */

  
  //  Translate each of characters in  a string in the command line and 
  //  Store them in str and Output them
  i = 0;
  while('\0' != argv[1][i] && i < N){
    str[i] = toupper(argv[1][i]);
    std::cout << str[i];
    ++i;
  }
  std::cout << std::endl;
  
  //  Normally terminated and return 0
  return(0);
}

/*
Nで宣言した文字数よりも多くを入れても出力されるので
入力する文字数の限度を決定した。
$ ./a.out abcdefghh
ABCDEFGHH
$ ./a.out abcdefghdjahfijldshfadhsfuiasyfhaewuf
Segmentation fault: 11
$ ./a.out abcdefghdjahfijldshfadhsfuiasyf
ABCDEFGHDJAHE/MAN:
*/
