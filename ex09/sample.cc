#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

class Student_info{//クラス定義
private:
  std::string FirstName, LastName, ID;//名字、名前、IDを保存する変数
  double Midterm, Final, Ex, Total;//期末テストの点数、演習の点数、総合点を保存する変数
  vector<double> Homework;//各演習の点数を保存する変数
public:
  //インターフェース
  Student_info();//デフォルトコンストラクタ
  Student_info(std::istream&);//コンストラクタ
  std::string first_name()const{return FirstName;};//名前を返すアクセス関数
  std::string last_name()const{return LastName;};//名字を返すアクセス関数
  std::string id()const{return ID;};//IDを返すアクセス関数
  double midterm()const{return Midterm;};//中間試験の点数を返すアクセス関数
  double final()const{return Final;};//期末試験の点数を返すアクセス関数
  double ex()const{return Ex;};//演習の点数を返すアクセス関数
  double total()const{return Total;};//総合点を返すアクセス関数
  std::vector<double> homework()const{return Homework;};//各演習の点数のデータを返すアクセス関数
  bool vaild()const{return !Homework.empty();};//演習を提出したかどうかを判別する関数
  std::istream& read(std::istream&);//データを読み込む関数
  double grade();//総合点を返す関数
  double median(vector<double> v); //演習のメジアンを算出する関数。
};

bool compare(const Student_info&, const Student_info&);//氏名を辞書順にソートするための関数
istream& read_hw(istream& is, vector<double>& v); //演習の点数を読み込みvectorに保存する関数。

Student_info::Student_info():Midterm(0),Final(0){}//デフォルトコンストラクタ
Student_info::Student_info(istream& is){read(is);}//コンストラクタ

double grade(double midterm, double final, const vector<double>& hw);//総合点を算出する関数
double median(vector<double> v);//メジアンを算出する関数

std::istream& Student_info::read(std::istream& is){//データを読み込む関数
  is >> ID >> FirstName >> LastName >> Midterm >> Final;
  read_hw(is, Homework);//演習点の読み込みと保存
  return is;
}

double Student_info::grade(){//総合点を返す関数
  Total = ::grade(Midterm, Final, Homework);//総合点を算出
  return Total;//総合点を返す
}

double grade(double midterm, double final, const vector<double>& hw){//総合点を算出する関数
  return 0.2*midterm + 0.4*final + 0.4*median(hw); //総合点を算出しその値を返す
}

int main()
{
  vector<Student_info> students;
  Student_info record;
    int snum = 0;

    const string bar(15,'-'); //５行毎の区切りに使用する棒線の作成。
    const string bar2(11,'-'); //５行毎の区切りに使用する棒線の作成。
    const string bar3(7,'-'); //５行毎の区切りに使用する棒線の作成。
    const string fiveline = "+" + bar + "+" + bar + "+" + bar2 
                             + "+" + bar3 + "+" + bar3 + "+"; //５行毎の区切りの行の作成。
    const string equal(15,'='); //最初と最後に使用する行に使用する線の作成。
    const string equal2(11,'='); //最初と最後に使用する行に使用する線の作成。
    const string equal3(7,'='); //最初と最後に使用する行に使用する線の作成。
    const string firstandlast = "+" + equal + "+" + equal + "+" + equal2 + "+"
                                 + equal3 + "+" + equal3 + "+"; //最初と最後の行の作成。
    cout.precision(1); //小数点以下の表示を一桁にする。
    cout.setf(ios::fixed,ios::floatfield); //固定小数点での出力。

    cout<< firstandlast << endl; //最初の行の表示

    while(record.read(cin)){//データの読み込み
      students.push_back(record);//読み込んだデータの保存
    }

    sort(students.begin(), students.end(), compare);//各データを氏名の辞書順にソート

    for(vector<Student_info>::size_type i=0; i!=students.size(); ++i){
      string space1(13-students[i].first_name().size(),' '); //苗字について必要なだけ空白を作る
      string space2(13-students[i].last_name().size(),' '); //名前について必要なだけ空白を作る


      if(students[i].vaild()){
	cout<< "| " << students[i].first_name() << space1 << " | " << students[i].last_name() << space2 
	    << " | " << students[i].id() << " | " 
	    << setw(5) << students[i].median(students[i].homework()) << " | " << setw(5) << students[i].grade()  
	    << " | "<<endl; //名前、苗字、学籍番号、および各数値の表示
      }

      else
	cout<< "| " << students[i].first_name() << space1 << " | " << students[i].last_name() << space2
	    << " | " << students[i].id() << " | " 
	    <<  setw(10) << " No grade" << setw(5) << " |" << endl; //名前、苗字、学籍番号の表示
      
      if((i+1)%5 == 0 && i>0 && i!=students.size()-1){
	cout<< fiveline << (i+1) << endl; //５行毎に区切る行の表示。行数の表示。
      }
    }
    cout<< firstandlast << endl; //最後の行の表示。
}
 
//演習の得点の詠み込み。
istream& read_hw(istream& is, vector<double>& v)
{
    if(is){
        double x; //一時的に値を保存する変数。
	v.clear(); //vを初期化。
	while(is>>x){ //xが数値なら入力。
	    v.push_back(x); //点数をvectorに保存。
	}
	is.clear(); //入力ストリームのエラーを解除。
    }
    return is;
}

//メジアンの計算。
double Student_info::median(vector<double> v)
{
  return ::median(v);
}

double median(vector<double> v){
    vector<double>::size_type size = v.size(), mid; //vの要素数、メジアンの位置を保存する変数。
    sort(v.begin(), v.end()); //得点をソート。
    mid = size/2; //データの中間値を計算。
    if(size%2 == 0) //データが偶数個の場合。
      return (v[mid]+v[mid-1])/2; //中央の2つの値の平均を返す。
    else //データが奇数個の場合。
      return v[mid]; //中央の値を返す。
}

//名前順にソートするための関数
bool compare(const Student_info& x, const Student_info& y)
{
  if(x.first_name() != y.first_name()) //名前が同名でないことを確認
        return (x.first_name() < y.first_name()); //辞書順でxの名前が早い場合1、そうでなければ0を返す
    else //名前が同名であった場合
        return (x.last_name() < y.last_name()); //辞書順でyの名前が早い場合1、そうでなければ0を返す
}