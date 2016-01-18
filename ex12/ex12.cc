/*
  SkeltonEx12.cc
  Skelton of C++ source code for Ex-12, prog2
  12-str
    Author: Yuta Sugii
    Date: Jan. 9th, 2016
*/
#include <iostream>
#include <ctype.h>

//  Put class Vec here
#include <memory>
#include <algorithm>
#include <string.h>

using namespace std;

template<class T>
class Vec{
public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  Vec() { create(); };
  explicit Vec(size_type n, const T& val = T()) { create(n, val); };
  Vec(const Vec& v) { create( v.begin(), v.end() ); };
  Vec<T>& operator=(const Vec& rhs);
  ~Vec() { uncreate(); };
  T& operator[](size_type i) { return data[i]; };
  const T& operator[](size_type i) const { return data[i]; };
  void push_back( const T& val ) {
    if( avail == limit ){
      grow();
    }
    unchecked_append( val );
  }
  size_type size() const { return avail - data; };
  iterator begin() { return data; };
  const_iterator begin() const { return data; };
  iterator end() { return avail; };
  const_iterator end() const { return avail; }; 
  void uncreate();

private:
  iterator data;
  iterator avail;
  iterator limit;
  allocator<T> alloc;
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);
  //void uncreate();
  void grow();
  void unchecked_append(const T&);
};

/*
  Vec<T>::operator=
    Assignment operator
*/
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
  //  Put source code below
    if (&rhs != this) {
      uncreate();
      create(rhs.begin(), rhs.end());
    }
    return *this;
}

/*
  Vec<T>::create()
    Initialize function (default)
*/
template <class T>
void Vec<T>::create()
{
  //  Put source code below
   data = avail = limit = 0;
}

/*
  Vec<T>::create()
    Initialize function with size and value
*/
template <class T>
void Vec<T>::create(size_type n, const T& val)
{
  //  Put source code below
  data = alloc.allocate(n); 
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

/*
  Vec<T>::create()
    Initialize function with iterators
*/
template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
  //  Put source code below
  data = alloc.allocate(j - i);
  limit = avail = std::uninitialized_copy(i, j, data);
}

/*
  Vec<T>::uncreate()
    Finalize function
*/
template <class T>
void Vec<T>::uncreate()
{
  //  Put source code below
  if (data) {
      iterator it = avail;
      while (it != data) alloc.destroy(--it);
      alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

/*
  Vec<T>::grow()
    Increase data size
*/
template <class T>
void Vec<T>::grow()
{
  //  Put source code below
  size_type new_size = max(2 * (limit - data), ptrdiff_t(1));
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = std::uninitialized_copy(data, avail, new_data);
  uncreate();
  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

/*
  Vec<T>::unchecked_append()
    Append data  
*/
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
  //  Put source code below
  alloc.construct(avail++, val);
}

// class Str here

class Str	{
public:
  friend std::istream& operator >> (std::istream&, Str&);
  typedef Vec<char>::size_type size_type;
  Str() {};
  Str(size_type n, char c) : data(n, c) {};
  Str(const char* cp)	{
    //  Put source code here
    std::copy(cp, cp + strlen(cp),
    	std::back_inserter(data));
  }
  template <class In> Str(In b, In e){
    //  Put source code here
  	std::copy(b,e,std::back_inserter(data));
  }
  char& operator[](size_type i) {
    //  Put source code here
    return data[i];
  };
  const char& operator[](size_type i) const {
    //  Put source code here
    return data[i];
  }
  size_type size() const { 
    //  Put source code here
    return data.size();
  }
  Str& operator += (const Str& s){
    //  Put source code here
    std::copy(s.data.begin(), s.data.end(),
    std::back_inserter(data) );
    return *this;
  }
  bool operator == (const Str& s) const {
    //  Put source code here
    if(s.size() == data.size()){
      for(Str::size_type i = 0;i != s.size();++i){
        if(data[i] != s[i]){
          return false;
        }
      }
      return true;
    }
    return false;
  }
  bool operator != (const Str& s) const {
    //  Put source code here
    if(s.size() == data.size()){
      for(Str::size_type i = 0;i != s.size();++i){
        if(data[i] != s[i]){
          return true;
        }
      }
    return false;
    }
  return true;
  }
  char* begin(){
    //  Put source code here
    return &data[0];
  }
  char* end(){
    //  Put source code here
    return &data[data.size()];
  }
private:
  Vec<char> data;
};
std::ostream& operator << (std::ostream&, const Str&);

std::ostream& operator << (std::ostream& os, const Str& s)
{
  //  Put source code here
  for(Str::size_type i = 0;i != s.size();++i)
    os << s[i];
  return os;
}

std::istream& operator >> (std::istream& is, Str& s)
{
  //  Put source code here
  s.data.uncreate();
  char c;
  while(is.get(c) && isspace(c));
  if(is){
    do s.data.push_back(c);
    while(is.get(c) && !isspace(c));
    if(is)
      is.unget();
  }
  return is;
}

Str operator + (const Str& s, const Str& t)
{
  //  Put source code here
  Str r = s;
  r+=t;
  return r;
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
