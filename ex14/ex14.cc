/*
  ex14.cc
  C++ source code for Ex-14, prog2
  14-handle
    Author: Yuta Sugii
    Date: Dec. 1st, 2015
*/
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
T* clone(T* p)
{
  return new T(*p);
}

//  Put Handle class below
template <class T> class Handle{
public:
	Handle():p(0){}
	Handle(const Handle& s):p(0){if(s.p) p=s.p->clone(); }
	Handle& operator=(const Handle&);
	~Handle(){delete p; }
	Handle(T* t): p(t) {}
	operator bool() const{return p;}
	T& operator*() const;
	T* operator->() const;
private:
	T* p;
 };

template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs){
	if(&rhs != this){
		delete p;
		p = rhs.p?clone(rhs.p): 0;
	}
	return *this;
}

template <class T>
T* Handle<T>::operator->() const{
	if(p) return p;
	throw runtime_error("unbound Hadle");
}

template <class T>
T& Handle<T>::operator*() const{
	if(p) return *p;
	throw runtime_error("unbound Hadle");
}

//  Put Core class below
class Core{
public:
	Core():midterm(0),final(0){ }
	Core(std::istream& is){ read(is);}
	std::string name( ) const ;
	virtual std::istream& read( std::istream& );
	virtual double grade() const;
	virtual ~Core(){}
	friend class Student_info;
	virtual Core* clone() const{return new Core(*this);}
	bool valid() const{ return !homework.empty();  }
protected:
	std::istream& read_common( std::istream& );
	double midterm, final;
	std::vector<double> homework;
private:
	std::string n;
};

//  Put Grad class below
class Grad: public Core {
public:
	Grad():thesis(0){}
	Grad(std::istream& is) { read(is);}
	double grade() const;
	std::istream& read(std::istream&);
protected:
	Grad* clone() const{ return new Grad(*this);}
private:
	double thesis;
};

bool compare(const Core&, const Core&);
double median(std::vector<double> v){
	std::vector<double>::size_type size = v.size(), mid;
 	if(size == 0) throw std::domain_error("No exercises");
  	std::sort(v.begin(),v.end());
	mid=size/2;
	if(size%2 == 0) return (v[mid]+v[mid-1])/2;
	else return v[mid];
}

double grade(double midterm, double final,std::vector<double> hw){
  	double median;
  	std::vector<double>::size_type size = hw.size(), mid;
  	if(size == 0) {
		throw std::domain_error("no exercises");
  	}
  	std::sort(hw.begin(),hw.end());
  	mid=size/2;
 	if(size%2 == 0){
 		median = (hw[mid]+hw[mid-1])/2;
  	}
  	else median = hw[mid];
  	return (0.2*midterm+0.4*final+0.4*median);
}

std::string Core::name() const{return n;}

double Core::grade() const{
	return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in){
	in >> n >> midterm >>final;
	return in;
}

std::istream& read_hw(std::istream& is, std::vector<double>& v){
	if(is){
		double x;
  		v.clear();
   		while(is>>x){
    		v.push_back(x);
   		}
   		is.clear();
 	}
  	return is;
}

std::istream& Core::read(std::istream& in){
	read_common(in);
	read_hw(in,homework);
	return in;
}

std::istream& Grad::read(std::istream& in){
	read_common(in);
	in>>thesis;
	read_hw(in,homework);
	return in;
}

double Grad::grade() const{
	return std::min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2){
	return c1.name() < c2.name();
}

bool comare_grades(const Core& c1, const Core& c2){
	return c1.grade() < c2.grade();
}

bool compare_Core_handles(const Handle<Core>& c1, const Handle<Core>& c2){
	return 0;
}

class Student_info{
public:
	Student_info() {}
	Student_info(std::istream& is){read(is);}
	std::istream& read(std::istream&);
	std::string name() const{
   		if(cp) return cp->name();
   		else throw std::runtime_error("uninitialized Student");
 	}
 	double grade() const{
   		if(cp) return cp->grade();
   		else throw std::runtime_error("uninitialized Stundent");
 	}
 	static bool compare(const Student_info& s1, const Student_info& s2){
   		return s1.name() < s2.name();
   	}
private:
 	Handle<Core> cp;
};

std::istream& Student_info::read(std::istream& is){
	char ch;
 	is>>ch;
 	if(ch=='U'){
   		cp=new Core(is);
 	}
 	else {
   		cp=new Grad(is);
 	}
 	return is;
}

//main function from here
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

