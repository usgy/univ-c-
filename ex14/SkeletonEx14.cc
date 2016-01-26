/*
  SkeltonEx14.cc
  C++ source code for Ex-14, prog2
  14-handle
    Author: Keitaro Naruse
    Date: Jan. 23th, 2007
*/
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

template <class T>
T* clone(T* p)
{
  return new T(*p);
}

//  Put Handle class below

//  Put Core class below

//  Put Grad class below

int main()
{
  std::vector< Handle<Core> > students;
  Handle<Core> record;
  char ch;
  string::size_type maxlen = 0;
  
  while(std::cin >> ch){
    if(ch == 'U'){
      record = new Core;
    }
    else {
      record = new Grad;
    }
    record -> read(cin);
    maxlen = max( maxlen, record->name().size() );
    students.push_back( record );
  }
  
  std::sort(students.begin(), students.end(), compare_Core_handles);
  
  for(std::vector< Handle<Core> >::size_type i = 0; i != students.size(); ++i){
    std::cout << students[i]->name()
	      << std::string(maxlen + 1 - students[i]->name().size(), ' ');
    if( students[i]->valid() ){
      double final_grade = students[i]->grade();
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

