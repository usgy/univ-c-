/*
  ex10-04.cc
    Sample source code for ex10-04
    This source code includes potential runtime errors or unintended run. 
    Find them through test procedures and Fix the.
    Author: Keitaro Naruse
    Date: 2012-12-19
 */

/*
  main()
    This program counts the number of characters appeared in the command line
 */

#include <iostream>

int main(int argc, char *argv[])
{
  //  Counter
  int i, j;
  //  Number of characters
  unsigned char n;
  
  //  Count the number of characters appeared in the command line
  for(i = 0; i < argc; ++i){
    for(j = 0; j != '\0'; ++j){
      n++;
    }
  }
  
  std::cout << n << std::endl;
  
  //  Normally terminated and return 0
  return(0);
}
