
#include <string>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//  Prototype
bool isEven(int);

//  Put prototype for my_search, here
template< class ForwardIterator1, class ForwardIterator2 >
ForwardIterator1 my_search( ForwardIterator1 b, ForwardIterator1 e, 
			    ForwardIterator2 b2, ForwardIterator2 e2 );

template< class InputIterator, class OutputIterator >
OutputIterator my_copy( InputIterator b, InputIterator e, OutputIterator d );

template< class BidirectionalIterator, class Predicate >
BidirectionalIterator my_partition( BidirectionalIterator b, 
				 BidirectionalIterator e, Predicate p);

int main(int argc, char *argv[])
 {
   std::string 
     src1 = "http://www.u-aizu.ac.jp/~naruse",
     src2 = "/ProgC++2008/index.html",
     src3 = "another", 
     query1 = "://";
  std::string::iterator i;
  std::vector<int> data;
  std::vector<int>::iterator sep;
  
  i = my_search( src1.begin(), src1.end(), query1.begin(), query1.end() );
  if( i == src1.end() ){
    std::cout << "[" << query1 << "]" << " is NOT found in [" 
	 << src1 << "]" << std::endl;
  }
  else{
    std::cout << "[" << query1 << "]" << " is found at [" 
	 << std::string( i, src1.end() ) << "]"  << std::endl;
  }

  i = my_search( src2.begin(), src2.end(), query1.begin(), query1.end() );
  if( i == src2.end() ){
    std::cout << "[" << query1 << "]" << " is NOT found in [" 
	 << src2 << "]" << std::endl;
  }
  else{
    std::cout << "[" << query1 << "]" << " is found at [" 
	 << std::string( i, src2.end() ) << "]"  << std::endl;
  }
  
  my_copy( src2.begin(), src2.end(), back_inserter(src1) );
  std::cout << src1 << std::endl;

  i = my_copy( src3.begin(), src3.end(), src1.begin() +  24);
  std::cout << src1 << std::endl;
  std::cout << "Following letters are [";
  while( i != src1.end() ){
    std::cout << *i;
    ++i;
  }
  std::cout << "]" << std::endl;
  
  for(int j = 0; j < 10; j++){
    data.push_back(j);
    std::cout << data[j] << " ";
  }
  std::cout << std::endl;
  
  sep = my_partition( data.begin(), data.end(), isEven );
  for( int j = 0; j < data.size(); ++j ){
    std::cout << data[j] << " ";
  }
  std::cout << std::endl << *sep << std::endl;
  
  for( int j = 0; j < data.size(); ++j ){
    data[j ] = 0;
    std::cout << data[j] << " ";
  }
  sep = my_partition( data.begin(), data.end(), isEven );
  std::cout << std::endl << *sep << std::endl;
  
  for( int j = 0; j < data.size(); ++j ){
    data[j ] = 1;
    std::cout << data[j] << " ";
  }
  sep = my_partition( data.begin(), data.end(), isEven );
  std::cout << std::endl << *sep << std::endl;
  
  return 0;
 }

 template<class ForwardIterator1, class ForwardIterator2>
 ForwardIterator1 my_search( ForwardIterator1 b, ForwardIterator1 e, 
			     ForwardIterator2 b2, ForwardIterator2 e2 )
{
if (b2==e2) return b;
  
  while (b!=e)
  {
    ForwardIterator1 it = b;
    ForwardIterator2 it2 = b2;
    while (*it==*it2) {
        ++it; ++it2;
        if (it2==e2) return b;
        if (it==e) return e;
    }
    ++b;
  }
  return e;

}

template< class InputIterator, class OutputIterator >
OutputIterator my_copy( InputIterator b, InputIterator e, OutputIterator d )
{
  while (b!=e) {
    *d = *b;
    ++d; ++b;
  }
  return d;
}

template< class BidirectionalIterator, class Predicate >
BidirectionalIterator my_partition( BidirectionalIterator b, BidirectionalIterator e, Predicate p)
{
  typename std::iterator_traits< BidirectionalIterator >::value_type x;

  while (true) {
    while (true)
      if (b == e)
        return b;
      else if (p(*b))
        ++b;
      else
        break;
    --e;
    while (true)
      if (b == e)
        return b;
      else if (!p(*e))
        --e;
      else
        break;
    iter_swap(b, e);
    ++b;
  }

}

bool isEven(int num)
{
  if( num % 2 == 0 ){
    return( true );
  }
  return( false );
}
