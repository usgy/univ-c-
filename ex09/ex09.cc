/*
Name: Yuta Sugii
Number: s1220135
Prog-Name: ex09.cc
*/
 
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <iterator>
 
using namespace std;
 
class Student_info{
public:
   
  //インターフェイス
  Student_info();
  Student_info(std::istream&);
  string first_name()const{return FirstName;};
  string last_name()const{return LastName;};
  string id()const{return ID;};
  double midterm()const{return Midterm;};
  double final()const{return Final;};
  double ex()const{return Ex;};
  double total()const{return Total;};
  std::vector<double> homework()const{ return Homework; };
  bool vaild()const{return !Homework.empty();};
  std::istream& read(std::istream&);
  double grade();
private:
  // 実装
  string FirstName, LastName, ID;
  double Midterm, Final, Ex, Total;
  vector<double> Homework;
};
 
//宣言文
bool compare(const Student_info&, const Student_info&);
istream& read_hw(istream&, vector<double>&);
double median(vector<double>);
 
//メンバ関数の定義
 
Student_info::Student_info(): Midterm(0),Final(0){}
Student_info::Student_info(istream& is){read(is);}
std::istream& Student_info::read(std::istream& is){
   //適切なコードを書く
  is >> ID >> FirstName >> LastName >>Midterm >> Final;
  read_hw(is, Homework);
  return is;
}
 
//総合得点の算出
double Student_info::grade(){
   
  Ex = median(Homework);
    Total = 0.2*Midterm + 0.4*Final + 0.4*Ex;
    return Total;
}
 
//適切なコードを書く   
bool compare( const Student_info& x, const Student_info& y){
   
  if(x.first_name() == y.first_name()){    
    return x.last_name() < y.last_name();
  }
   
  else return x.first_name() < y.first_name();
}
 
// メジアンの計算
double median(vector<double> v){
   
  vector<double>::size_type size = v.size();
  vector<double>::size_type mid;
   
  if(size == 0) return 0;  
   
  else{
    sort(v.begin(),v.end());
     
    mid = size/2;
     
    if(size % 2 == 0) return (v[mid] + v[mid-1])/2;
     
    else return v[mid];
     
  }
}
 
istream& read_hw(istream& in, vector<double>& v){
   
  if(in){
     
    double x;
    v.clear();
    while(in>>x){
      v.push_back(x);
    }
    in.clear();
  }
  return in;
}
 
int main(){
   
  int j,idnum,finum,secnum,count = 0;
   
  cout<<"+===========+===========+=========+=====+=====+" << endl;
   
  vector<Student_info>students;
  Student_info record;
   
  while(record.read(cin)){
    students.push_back(record);
  }
   
  sort(students.begin(), students.end(), compare);
  //出力
  for(vector<Student_info>::size_type i = 0; i!= students.size(); ++i){
     
    students[i].grade();
     
    idnum = 9 - students[i].id().size();
     
    finum = 11 - students[i].first_name().size();
     
    secnum = 11 - students[i].last_name().size();
     
    cout << "|" << students[i].first_name();
      
     for(j = 1;j<finum;j++){
        
       cout<<" ";
        
     }
      
     // 姓を出力
     cout<<" |" << students[i].last_name();
      
     for(j = 1; j<secnum;j++){
       cout<<" ";
     }
      
     // IDを入力
     cout<<" |"<< students[i].id();
     
    for(j = 1;j<idnum;j++){
      cout<<" ";
    }
     
    //数字にする
    cout.setf(ios::fixed,ios::floatfield);
    cout.setf(ios::showpoint);
     
    cout<<"|";
     
    cout<<setw(5)<<setprecision(1)<<students[i].ex()<<"|";
    cout<<setw(5)<<setprecision(1)<<students[i].total()<<"|" << endl;
     
    ++count;
     
    if(count % 5 ==  0){
       
      cout<< "+-----------+-----------+---------+-----+-----+ " << count << endl;      
    }   
  }
  cout<< "+===========+===========+=========+=====+=====+" << endl;
}
