/*
  SkeltonEx13.cc
  C++ source code for Ex-13, prog2
  13-inherit
    Author: Yuta Sugii
    Date: Jan. 25th, 2016
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>
#include <iomanip> 

using namespace std;


istream& read_hw(istream& is, vector<double>& hw){
   if(is) {
    double a;
    hw.clear();
    while( is >> a ){
      hw.push_back(a);
    }
    is.clear();
  }
  return is;
}

double median(vector<double> v){
  vector<double>::size_type size = v.size(), mid;

  sort(v.begin(),v.end());
  mid = size / 2;
  if(size % 2 == 0)
    return(v[mid] + v[mid-1]) / 2;
  else
    return v[mid];
 }

double grade(double midterm, double final, const vector<double>& hw){
  double ex_med = median(hw);
  return 0.2 * midterm + 0.4 * final + 0.4 * ex_med;
}



/*
  Core class
    Provide core functions for student information
*/
class Core{
//  Put code below
  public:
  Core();
  Core(std::istream&);
  std::string name() const{return n;}
  std::istream& read(std::istream& in)
  {
    read_common(in);
    read_hw(in, homework);
    return in;
  }

  virtual double grade() const{
        return ::grade(midterm, final, homework);
        }
  friend class Student_info;
protected:
  std::istream& read_common(std::istream& in)
  {
        in >> n >> midterm >> final;
            return in;
              }
  double midterm, final;
  std::vector<double> homework;
  virtual Core* clone() const{return new Core(*this);}
private:
  std::string n;
};

Core::Core() : midterm(0), final(0){}
Core::Core(std::istream& is){read(is);}

/*
  Grad class
  Provide a class for a graduate student
*/
class Grad: public Core {
//  Put code below
  public:
  Grad();
  Grad(std::istream&);
  std::istream& read(std::istream& in){
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
  }
  double grade() const{
        return min(Core::grade(), thesis);
        }
protected:
  virtual Core* clone() const{return new Grad(*this);}
private:
  double thesis;
};

/*
  Student_info class
  Provide a hundle class
*/
class Student_info{
//  Put code below
//  Student_info class should have valid() function
  private:
  Core *cp;
  public:
  bool valid() const{return !(cp->homework.size() == 0);}
  double grade() const{
    return cp->grade();
}

  Student_info() : cp(0) {}
  Student_info( std::istream& is ) : cp(0){read(is);}
  Student_info( const Student_info& is );
  ~Student_info(){delete cp;}
  std::istream& read(std::istream&);
  std::string name() const{
    if(cp) return cp->name();
    else throw std::runtime_error("uninitialized");
  }

  static bool compare(const Student_info& s1, const Student_info& s2){
    return s1.name() < s2.name();
  }

  Student_info& operator=(const Student_info& s);
};

Grad::Grad() : thesis(0){}
Grad::Grad(std::istream& is){ read(is);}


std::istream& Student_info::read( std::istream& is){
  delete cp;
  char ch;
  is >> ch;
  if(ch == 'U') {
    cp = new Core(is);
  }
  else{
    cp = new Grad(is);
  }
  return is;
}

Student_info::Student_info(const Student_info& s):cp(0){
  if(s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s){
  if(&s != this) {
    delete cp;
    if(s.cp)
      cp = s.cp->clone();
    else
      cp = 0;
  }

  return *this;
}

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
