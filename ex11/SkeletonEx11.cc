/*
  ex11.cc
  Skelton of C++ source code for Ex-11, prog2
  11-abstdata
    Author: Keitaro Naruse
    Date: Dec. 19th, 2006
*/

#include <memory>
#include <algorithm>

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
private:
  iterator data;
  iterator avail;
  iterator limit;
  allocator<T> alloc;
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);
  void uncreate();
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
}

/*
  Vec<T>::create()
    Initialize function (default)
*/
template <class T>
void Vec<T>::create()
{
  //  Put source code below
}

/*
  Vec<T>::create()
    Initialize function with size and value
*/
template <class T>
void Vec<T>::create(size_type n, const T& val)
{
  //  Put source code below
}

/*
  Vec<T>::create()
    Initialize function with iterators
*/
template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
  //  Put source code below
}

/*
  Vec<T>::uncreate()
    Finalize function
*/
template <class T>
void Vec<T>::uncreate()
{
  //  Put source code below
}

/*
  Vec<T>::grow()
    Increase data size
*/
template <class T>
void Vec<T>::grow()
{
  //  Put source code below
}

/*
  Vec<T>::unchecked_append()
    Append data  
*/
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
  //  Put source code below
}

/*
  main()
 */
int main(int argc, char *argv[])
{
  Vec<int> c1;
  Vec<int> c2( 8 );
  Vec<int> c3( 4, 1 );
  Vec<int> c4( c3 );
  Vec<int>::iterator i;
  int j;
  
  //  Check for default constructor and iterator
  cout << "c1: #1" << std::endl;
  for(i = c1.begin(); i != c1.end(); ++i){
    cout << *i << " ";
  }
  cout << std::endl;
  
  //  Check for constructor with size, and operator[] for read
  cout << "c1: #2" << std::endl;
  c1.push_back( 0 );
  for( j = 0; j != c1.size(); ++j ){
    cout << c1[ j ] << " ";
  }
  cout << std::endl;
  
  //  Check for constructor with size
  cout << "c2: #1" << std::endl;
  for( i = c2.begin(); i != c2.end(); ++i ){
    cout << *i << " ";
  }
  cout << std::endl;
  
  //  Check for constructor with size and value
  cout << "c3: #1" << std::endl;
  for( j = 0; j != c3.size(); ++j ){
    cout << c3[ j ] << " ";
  }
  cout << std::endl;
  
  //  Check for constructor with another container
  cout << "c4" << std::endl;
  for( j = 0; j != c4.size(); ++j ){
    cout << c4[ j ] << " ";
  }
  cout << std::endl;
  
  //  Check for operator[] for write
  c3[0] = 0; 
  c3[1] = 1;
  c3[2] = 2;
  c3[3] = 3;
  cout << "c3: #2" << std::endl;
  for( j = 0; j != c3.size(); ++j ){
    cout << c3[ j ] << " ";
  }
  cout << std::endl;

  //  Check for operator =
  c2 = c3;
  cout << "c2: #2" << std::endl;
  for( j = 0; j != c2.size(); ++j ){
    cout << c2[ j ] << " ";
  }
  cout << std::endl;
  
  return 0;
}
