/*
  ex10-03.cc
    Sample source code for ex10-03
    This source code includes potential runtime errors. 
    Find them through test procedures and Fix the.
    Author: Yuta Sugii
    Date: 2015/12/16
 */

/*
  main()
    This program reverses the order of characters given in the command line
 */

#include <iostream>
#include <string>
#include <string.h>

int main(int argc, char *argv[])
{
  //  Counter
  int i;
  //  Data number
  int n;

  
  //  Set the number of integers
  n = strlen( argv[1] ) - 1;

  //  Memory allocation
  char data[n];
  //  Temporary
  char tmp[n];
  
  // Copy intergers to data
  for(i = 0; i <= n; ++i){
    data[i] = argv[1][i];
    // std::cout << "*(data + i) = " << *(data+i) << std::endl;
  }

  
  //  Reverse the order of integers and Store them 
  for(i = 0; i <= n / 2; ++i){
    tmp[i] = data[i];
    data[i] = data[n-i];
    data[n-i] = tmp[i];
  }
  
  //  Output the reversed integers
  for(i = 0; i <= n; ++i){
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
  
  //  memory free
  //delete data;
  
  //  Normally terminated and return 0
  return(0);
}
