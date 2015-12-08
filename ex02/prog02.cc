/*
	Filename: prog02.cc
	Outline: ユーザーの学籍番号、名、姓をファイルのリダイレクトを用いて入力し、表を作成する
	Author: Yuta Sugii
	Student ID: s1220135	
	Date: 2015-10-06
*/

#include <iostream>
#include <string>

int main(){
	const std::string bar0(22, '='); //表の縁を作成
	const std::string bar05(22, '-');
	const std::string bar = '+' + bar0 + '+' + bar0 + '+' + bar0 + '+'; // 最初と最後のバーの定義
	const std::string bar5 = '+' + bar05 + '+' + bar05 + '+' + bar05 + '+'; // 5行ごとのバーの定義

	std::string sid, givenname, surname; //データ入力先を定義
	int count=0; //読み込んだデータの行数をカウントする


	std::cout << bar << std::endl;

	while(std::cin >> sid >> givenname >> surname) //データを入力
	{
		count++; //入力データがあるため、カウンターを増やす

		//指定された文字数をオーバーした場合はプログラムを強制終了する
		if((givenname.size()>20) || (surname.size()>20) || (sid.size()>17))
		{
			std::cout << "Please fix your input file..." << std::endl;
			std::cout << "Finish this program" << std::endl;

			return 1;
		}
		//スペース作成
		const std::string gspaces(22 - givenname.size(), ' '); // given name spaces
		const std::string sspaces(22 - surname.size(), ' '); // sur name spaces
		const std::string ispaces(22 - sid.size(), ' '); // sid spaces

		std::cout << '|' << givenname << gspaces << '|' << surname << sspaces << '|' << sid << ispaces << '|' << std::endl; //表の中身の生成

		if(count%5==0) // 5行毎にバーを入れる
		{
			std::cout << bar5 << count << std::endl;
		}
	}

	std::cout << bar << std::endl;

	return 0;

}