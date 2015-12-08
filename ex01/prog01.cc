/*
  prog01.cc
  概要：ユーザの姓と名を順に入力し、それを整形して標準出力に出力する
  Author: Yuta Sugii
  Date: 2015-10-06
*/
#include <iostream>
#include <string>

int main()
{
  //Hearing user sur name
  std::cout << "Please input your surname" << std::endl;

  std::string surname; //Define surname
  std::cin >> surname;  // Input surname

  //Hearing user given name
  std::cout << "Please input your given name" << std::endl;

  std::string givenname; //Define givenname
  std::cin >> givenname; //Input givenname

  const std::string spaces(givenname.size()+surname.size()+13, '*'); //Define spaces
  const std::string second(givenname.size() + surname.size() +11, ' '); //Define second

  //Output data
  std::cout << spaces << std::endl;
  std::cout << '*' << second << '*' << std::endl;
  std::cout << "* Hello, " << givenname << ' '<< surname  << "! *" << std::endl;
  std::cout <<  '*' << second << '*' << std::endl;
  std::cout << spaces << std::endl;

  return 0;
}
