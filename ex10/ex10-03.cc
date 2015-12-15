/*
  ex10-03.cc
    Sample source code for ex10-03
    This source code includes potential runtime errors. 
    Find them through test procedures and Fix the.
    Author: Keitaro Naruse
    Date: 2012-12-19
 */

/*
  main()
    This program reverses the order of characters given in the command line
 */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  //  Counter
  int i;
  //  Data number
  int n;
  //  Data
  std::string *data;
  //  Temporary
  std::string tmp;
  
  
  
  //  Set the number of integers
  n = argc - 1;
  
  //  Memory allocation
  data = new std::string[n];
  
  // Copy intergers to data
  for(i = 0; i < n; ++i){
    *(data + i) = std::string(argv[i + 1]);
  }
  
  //  Reverse the order of integers and Store them 
  for(i = 0; i < n / 2; ++i){
    tmp = *(data + i);
    *(data + i) = *(data + n - i - 1);
    *(data + n  - i - 1) = tmp;
  }
  
  //  Output the reversed integers
  for(i = 0; i < n; ++i){
    std::cout << *(data + i) << " ";
  }
  std::cout << std::endl;
  
  //  memory free
  delete data;
  
  //  Normally terminated and return 0
  return(0);
}
