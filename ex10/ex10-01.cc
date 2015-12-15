/*
  ex10-01.cc
    Sample source code for ex10-01
    This source code includes potential runtime errors. 
    Find them through test procedures and Fix the.
    Author: Keitaro Naruse
    Date: 2012-12-19
 */

/*
  main()
    This program traslates lower characters into upper ones
    in a string given in a command line
 */

#define N 8

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
  //  String
  char str[N];
  //  Counter
  int i;
  
  //  Check the number of arguments and Abort if it is less than 2
  if(2 > argc){
    std::cerr << "uasage: ex01-01 string" << std::endl;
    std::cerr << "string must be less than eight characters" << std::endl;
    //  Abnormally terminated and return -1
    return(-1);
  }
  
  //  Translate each of characters to uppercase in the command line string and 
  //  Store them in str and Output them
  for(i = 0; i < N; ++i){
    str[i] = toupper(argv[1][i]);
    std::cout << str[i];
  }
  std::cout << std::endl;
  
  //  Normally terminated and return 0
  return(0);
}
