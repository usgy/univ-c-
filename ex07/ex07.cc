#include<vector>
#include<string>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<iterator>
#include<map>

using namespace std;


vector<string> split( const string& );
bool space( char );
bool not_space( char c );

int main(){

  map< string, vector<int> > counters;
  vector<string> words;
  string grep, s, tmp;
  int line_num = 0;   

  getline( cin, grep );
  
  while( getline( cin, s ) ) {

    ++line_num;

    words = split( s );

    vector<string>::iterator it = words.begin();

    while( it != words.end() ){
      
      tmp = *it;

      for( string::size_type i = 0 ; i != tmp.size() ; ++i ) {
	tmp[ i ] = tolower( tmp[i] );
      }
      
      if( tmp.size() > 1 ) {
	if( !isalnum( tmp[ 0 ] ) ) {
	  tmp = tmp.substr( 1, tmp.size() - 1 );
	}
      }
      
      if( tmp.size() > 1 ) {
	if( !isalnum( s[ tmp.size() - 1 ]) && tmp[ tmp.size() - 1 ] != '+' ) {
	  
	  tmp = tmp.substr( 0, tmp.size() - 1 );
	  
	  if( !isalnum( tmp[ tmp.size() - 1 ]) && 
	      tmp[ tmp.size() - 1 ] != '+' && 
	      tmp[ tmp.size() - 1 ] != '.' ) {
	    
	    tmp = tmp.substr( 0, tmp.size() - 1 );
	    
	  }
	}
      }
      counters[ tmp ].push_back( line_num );
      ++it;
    }
  }

  vector<int>::const_iterator it = counters[ grep ].begin();
  cout << grep << " is appeared at ";
  cout << *it;
  ++it;
  while( it != counters[ grep ].end() ){
    cout << " " << *it;
    ++it;
  }
  cout << endl;
  return 0;
  
}

vector<string> split( const string& str ) {

  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();

  while( i != str.end() ){
 
    i = find_if( i, str.end(), not_space );

     iter j = find_if( i, str.end(), space );

    if( i != str.end() ) {
      ret.push_back( string( i, j ) );
    }

    i = j;
  }
  return ret;
}

bool space( char c ){ return  isspace( c ); }
bool not_space( char c ){ return !isspace( c ); }

