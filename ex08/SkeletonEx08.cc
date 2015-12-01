/*
  SkeltonEx08.cc
    C++ source code for Ex-8, Prog C++
    8-template
    Author: Keitaro Naruse
    Date: Nov. 11th, 2008
*/
#include <string>
#include <iostream>
#include <iterator>
#include <vector>

// using namespace std;

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

/*
  main()
    main function
 */
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
  
  // my_search() test1
  // Try to search query1 in src1
  i = my_search( src1.begin(), src1.end(), query1.begin(), query1.end() );
  if( i == src1.end() ){
    std::cout << "[" << query1 << "]" << " is NOT found in [" 
	 << src1 << "]" << std::endl;
  }
  else{
    std::cout << "[" << query1 << "]" << " is found at [" 
	 << std::string( i, src1.end() ) << "]"  << std::endl;
  }
  
  //  my_search() test2
  //  Try to search query1 in src2
  i = my_search( src2.begin(), src2.end(), query1.begin(), query1.end() );
  if( i == src2.end() ){
    std::cout << "[" << query1 << "]" << " is NOT found in [" 
	 << src2 << "]" << std::endl;
  }
  else{
    std::cout << "[" << query1 << "]" << " is found at [" 
	 << std::string( i, src2.end() ) << "]"  << std::endl;
  }
  
  //  my_copy() test1
  //  copy src2 at the end of src1
  my_copy( src2.begin(), src2.end(), back_inserter(src1) );
  std::cout << src1 << std::endl;
  
  //  my_copy() test2
  //  copy src3 from the 24th letter of src1 
  i = my_copy( src3.begin(), src3.end(), src1.begin() +  24);
  std::cout << src1 << std::endl;
  std::cout << "Following letters are [";
  while( i != src1.end() ){
    std::cout << *i;
    ++i;
  }
  std::cout << "]" << std::endl;
  
  //  Test for my_partition
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

/*
  my_search()
  Generic function work same as search in C++ standard library
*/
 template<class ForwardIterator1, class ForwardIterator2>
 ForwardIterator1 my_search( ForwardIterator1 b, ForwardIterator1 e, 
			     ForwardIterator2 b2, ForwardIterator2 e2 )
{
  //  Put source code below
}

/*
  my_copy()
     Generic function work same as copy in C++ standard library
 */
template< class InputIterator, class OutputIterator >
OutputIterator my_copy( InputIterator b, InputIterator e, OutputIterator d )
{
  //  Put source code below
}

template< class BidirectionalIterator, class Predicate >
BidirectionalIterator my_partition( BidirectionalIterator b, BidirectionalIterator e, Predicate p)
{
  typename std::iterator_traits< BidirectionalIterator >::value_type x;
  
  //  Put source code below
  //  You can use std::iter_swap(i, j);
  //  for exchanging the countents of iterators i and j
}

bool isEven(int num)
{
  if( num % 2 == 0 ){
    return( true );
  }
  return( false );
}
