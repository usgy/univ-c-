/*
  SkeltonEx12.cc
  Skelton of C++ source code for Ex-12, prog2
  12-str
    Author: Keitaro Naruse
    Date: Jan. 9th, 2007
*/
#include <iostream>
#include <ctype.h>

//  Put class Vec here

class Str	{
public:
  friend std::istream& operator >> (std::istream&, Str&);
  typedef Vec<char>::size_type size_type;
  Str() {};
  Str(size_type n, char c) : data(n, c) {};
  Str(const char* cp)	{
    //  Put source code here
  }
  template <class In> Str(In b, In e)	{
    //  Put source code here
  }
  char& operator[](size_type i) {
    //  Put source code here
  };
  const char& operator[](size_type i) const {
    //  Put source code here
  }
  size_type size() const { 
    //  Put source code here
  }
  Str& operator += (const Str& s){
    //  Put source code here
  }
  bool operator == (const Str& s) const {
    //  Put source code here
  }
  bool operator != (const Str& s) const {
    //  Put source code here
  }
  char* begin(){
    //  Put source code here
  }
  char* end(){
    //  Put source code here
  }
private:
  Vec<char> data;
};
std::ostream& operator << (std::ostream&, const Str&);

std::ostream& operator << (std::ostream& os, const Str& s)
{
  //  Put source code here
}

std::istream& operator >> (std::istream& is, Str& s)
{
  //  Put source code here
}

Str operator + (const Str& s, const Str& t)
{
  //  Put source code here
}

int main(int argc, char* argv[])
{
  Str s1;
  Str s2(8, 'a');
  Str s3("Hello! How are you?");
  Str s4(s3.begin(), s3.end());
  
  std::cout << "s1:[" << s1 << "]" << std::endl; 
  std::cout << "s2:[" << s2 << "]" << std::endl; 
  std::cout << "s3:[" << s3 << "]" << std::endl; 
  std::cout << "s4:[" << s4 << "]" << std::endl;
  if(s3 == s4){
    std::cout << "#1: s3 is same as s4" << std::endl;
  }
  else {
    std::cout << "#1: s3 is different from s4" << std::endl;
  }
  s4[0] = 'h';
  std::cout << "s4:[" << s4 << "]" << std::endl;
  if(s3 == s4){
    std::cout << "#2: s3 is same as s4" << std::endl;
  }
  else {
    std::cout << "#1: s3 is different from s4" << std::endl;
  }
  std::cout << "Finished" << std::endl;
  
  return 0;
}
