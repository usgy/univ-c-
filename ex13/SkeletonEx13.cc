/*
  SkeltonEx13.cc
  C++ source code for Ex-13, prog2
  13-inherit
    Author: Keitaro Naruse
    Date: Jan. 16th, 2007
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>
#include <iomanip> 

/*
  Core class
    Provide core functions for student information
*/
class Core{
//  Put code below
};

/*
  Grad class
  Provide a class for a graduate student
*/
class Grad: public Core {
//  Put code below
};

/*
  Student_info class
  Provide a hundle class
*/
class Student_info{
//  Put code below
//  Student_info class should have valid() function
};

/*
  main()
*/
int main(int argc, char* argv[])
{
  std::vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;
  
  while( record.read(cin) ){
    maxlen = max( maxlen, record.name().size() );
    students.push_back( record );
  }
  
  std::sort(students.begin(), students.end(), Student_info::compare);
  
  for(std::vector<Student_info>::size_type i = 0; i != students.size(); ++i){
    std::cout << students[i].name()
	      << std::string(maxlen + 1 - students[i].name().size(), ' ');
    if( students[i].valid() ){
      double final_grade = students[i].grade();
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << final_grade
		<< std::setprecision(prec);
    }
    else{
      std::cout << "Caanot evaluate";
    }
    std::cout << std::endl;
  }
  
  return 0;
}
