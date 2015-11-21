/*
	Filename: ex03.cc
	Outline: ユーザーのファイルをリダイレクトを用いて入力し、成績表を作成する
	Author: Yuta Sugii
	Student ID: s1220135	
	Date: 2015-10-24
*/

#include <iostream>
#include <ios>
#include <iomanip> 
#include <string>
#include <vector>
#include <algorithm>

int main(){
	const std::string bar0(12, '='); //表の縁を作成
	const std::string id0(9, '='); 
	const std::string num0(7, '='); 
	const std::string bar05(12, '-');
	const std::string id05(9, '-');
	const std::string num05(7, '-');
	const std::string bar = '+' + bar0 + '+' + bar0 + '+' + id0 + '+' + num0 + '+' + num0 + '+' + num0 + '+' + num0 + '+'; // 最初と最後のバーの定義
	const std::string bar5 = '+' + bar05 + '+' + bar05 + '+' + id05 + '+'+ num05 + '+'+ num05 + '+'+ num05 + '+' + num05 + '+'; // 5行ごとのバーの定義

	std::string sid, givenname, surname; //データ入力先を定義
	double sum, ave, medi, x, sogo, mid, last;
	int count=0,size=0; //読み込んだデータの行数をカウントする
	std::vector<double> homework; //演習課題の得点を格納するためのベクトル
	homework.clear(); //初期化

	std::cout << bar << std::endl; //表形式の表示
	while(1)  //データを入力
	{
		if((std::cin >> sid >> givenname >> surname) == 0) break;
		count++; //表示する学生の数をカウントするカウンターを増やす

		std::cin >> mid >> last;

		while(1){
			std::cin >> x;
			homework.push_back(x); //演習の得点を格納する
			if(x == -1) break;
			//std::cout << x << std::endl;
		}


		//以下、平均・中央値・合計の計算

		std::vector<double>::size_type size = homework.size();
		size -= 1; //最後の-1の分サイズから引く
		if(size != 0) homework.pop_back(); //最後の-1を削除

		std::sort(homework.begin(), homework.end());

		for(int i=0; i<size; i++){
			sum += homework[i];
		}
		ave = (sum/size);
		if(size%2 == 0){
			medi = (homework[size/2] + homework[size/2 - 1])/2;
		}
		else{
			medi = homework[size/2];
		}
		if(size != 0){
		sogo = mid * 0.20 + last * 0.40 + medi * 0.40;//中間試験の点数を20%，期末試験の点数を40%，演習課題のメジアンを40%
		}
		else{
			sum = 0; ave = 0; medi = 0;
			sogo = mid * 0.20 + last * 0.40;
		}

		std::cout << '|' << std::setw(12) << std::left << givenname;
		std::cout << '|' << std::setw(12) << std::left << surname;
		std::cout << '|' << std::setw(9) << std::left << sid;
		std::cout << '|' << std::setw(7) << std::right << std::fixed << std::setprecision(1)<< sum;
		std::cout << '|' << std::setw(7) << std::right << std::fixed << std::setprecision(1)<< ave;
		std::cout << '|' << std::setw(7) << std::right << std::fixed << std::setprecision(1)<< medi;
		std::cout << '|' << std::setw(7) << std::right << std::fixed << std::setprecision(1)<< sogo << '|' << std::endl;

		if(count%5==0) // 5行毎にバーを入れる
		{
			std::cout << bar5 << count << std::endl;
		}

		//初期化
		sum = 0; ave = 0; medi = 0; homework.clear();
	}

	std::cout << bar << std::endl;

	return 0;


}