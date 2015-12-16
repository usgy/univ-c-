/*
  ex10-04.cc
    Sample source code for ex10-04
    This source code includes potential runtime errors or unintended run. 
    Find them through test procedures and Fix the.
    Author: Yuta Sugii
    Date: 2015/12/16
 */

/*
  main()
    This program counts the number of characters appeared in the command line
 */

#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
  //  Counter
  int i, j, len=0, sum=0;
  //  Number of characters
  unsigned char n;
  
  for(i = 1; i < argc; i++)
  {
    /* code */
    len = strlen( argv[i] );
    //std::cout << len << std::endl;
    sum += len;
  }

  //  Count the number of characters appeared in the command line
  // for(i = 0; i < len; ++i){
  //   for(j = 0; j != '\0'; ++j){
  //     n++;
  //   }
  // }
  
  //出力
  std::cout << sum << std::endl;
  
  //  Normally terminated and return 0
  return(0);
}
