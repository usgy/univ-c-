/*
	Filename: ex04.cc
	Outline: list4.txtのデータを正しく入力し、表として表示するプログラム
	Author: Yuta Sugii
	Student ID: s1220135	
	Date: 2015-10-27
*/

#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

using namespace std;

//構造体の定義
struct Student_info {
  string ID; //学籍番号
  string GivenName; //名
  string SurName; //姓
  double Midterm; //演習の成績
  double Final; //期末考査の成績
  vector<double> Execise; //演習の成績
};

//宣言
istream& read_hw(istream&, vector<double>&);

istream& read(istream& is, Student_info& s){
  is >> s.ID >> s.GivenName >> s.SurName;
  is >> s.Midterm >>s.Final;
  //演習の得点の読込みは別の関数に行う
  read_hw(is, s.Execise);
  return is;
}

  istream& read_hw(istream& is, vector<double>& v){
    if(is){
      double x; //毎回の演習の成績
      v.clear();
      while(is >> x){
		v.push_back(x);
      }
      is.clear();
    }
    return is;
  }

double median(vector<double> v){
  vector<double>::size_type size = v.size(), mid;
  if(size == 0)
    throw domain_error("要素数が０のメジアン");
  sort( v.begin(), v.end());
  mid = (size)/ 2;
  if((size)%2 == 0)
    return ((v[mid] + v[mid -1])/2);
  else
    return v[mid];
}

double grade(double midterm, double final, const vector<double>& hw, double& ex_mid, double& ex_avg, double& ex_sum)
{
  if(hw.size() == 0)
    throw std::domain_error("演習回数が0");
  ex_mid = median(hw);
  ex_sum = 0;
  for(vector<double>::size_type i=0; i!=hw.size(); ++i){
    ex_sum += hw[i];
  }
  ex_avg = ex_sum / hw.size();
  return 0.2 * midterm + 0.4 * final + 0.4 * ex_mid;
}


bool compare( const Student_info& x, const Student_info& y)
{
  // x とyのGivenNameが異なるときはGivenNameを比較
  if(x.GivenName != y.GivenName)
    return(x.GivenName < y.GivenName);
  //xとyのGivenNameが同じときはSurNameを比較
  else
    return (x.SurName < y.SurName);
}

int main(){
	const std::string bar0(22, '='); //表の縁を作成
	const std::string bar05(22, '-');
	const std::string bar = "+=============+=============+===========+=======+=======+=======+=======+"; // 最初と最後のバーの定義
	const std::string bar5 = "+-------------+-------------+-----------+-------+-------+-------+-------+"; // 5行ごとのバーの定義

	int count = 0;

	std::vector<Student_info> students;  //学生全体のデータ
	Student_info record; //学生１人分のデータ
	
	// 標準入力ストリームからデータの読込み
	// 読み込んだデータはrecordという変数に一時的に格納
	while( read( cin, record ) ){
	  // recordをvectorに追加
	  students.push_back(record);
	}
	
	
	//読み込んだデータがなくなるとループは終了
	// read関数の戻り値が偽: falseになるから
	// データがないときにcinを評価するとfalse

	//学生データを名前順番にソート
	sort(students.begin(), students.end(), compare);
	//学生のデータを出力
	std::cout << bar << std::endl; //表形式の表示
	for(vector<Student_info>::size_type i = 0; i!= students.size(); ++i){
	  //総合得点、演習メジアン、演習平均、演習合計
	  double total, ex_med, ex_avg, ex_sum;
	  //計算
	  // grade関数の中で例外が発生するかもしれないので
	  try{
	    total = grade(students[i].Midterm, 
			  students[i].Final, students[i].Execise, ex_med, ex_avg, ex_sum);
	    //画面出力
		std::cout << "| " << std::setw(11) << std::left << students[i].GivenName;
		std::cout << " | " << std::setw(11) << std::left << students[i].SurName;
		std::cout << " | " << std::setw(9) << std::left << students[i].ID;
		std::cout << " | " << std::setw(5) << std::right << std::fixed << std::setprecision(1)<< ex_sum;
		std::cout << " | " << std::setw(5) << std::right << std::fixed << std::setprecision(1)<< ex_avg;
		std::cout << " | " << std::setw(5) << std::right << std::fixed << std::setprecision(1)<< ex_med;
		std::cout << " | " << std::setw(5) << std::right << std::fixed << std::setprecision(1)<< total;
		std::cout << " |" << std::endl;
		count++;
	  }
	  catch(std::domain_error){
	  	//画面出力
		std::cout << "| " << std::setw(11) << std::left << students[i].GivenName;
		std::cout << " | " << std::setw(11) << std::left << students[i].SurName;
		std::cout << " | " << std::setw(9) << std::left << students[i].ID;
	    std::cout << " | no exercises                  |" << std::endl;
	    count++;
	  }
	  if(count%5==0) // 5行毎にバーを入れる
	    {
	      std::cout << bar5 << count << std::endl;
	    }
	}
	  std::cout << bar << std::endl;
}
