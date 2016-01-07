#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

#define FULL_FUEL 100 //燃料のMAX値
#define INIT_FUEL 100 //燃料の初期設定
#define DISTANCE 100 //燃料距離
#define METER_ELEMENT_NUM 10 //メーターの目盛の数
#define WAIT 10000 //時間稼ぎのためのウェイト

class car
{
	char *meterl; //残りの燃料の可視化
	int fuel; //残りの燃料
	int rest_distance; //残りの距離
Public:
	car(); //コンストラクタ
	~car(); //デストラクタ
	void set_meter(void); //meterに現在の燃料の状況を表示
	void move_car(void);
};

car::car()
{
	rest_distance=DISTANCE;
	fule=INIT_FUEL;
	meter=(char*)malloc(FULL_FUEL * 2 + 1);

	//メモリの確保に失敗したときの処理（省略）
}

car::~car()
{
	free(meter);
}

void car::set_meter(void)
{
	int count_fuel = 0;
	int fuel_per_square;
	char full_fuel[] = "■■■■■■■■■■"; //燃料有り
	char empty_fuel[] = "□□□□□□□□□□"; //燃料なし

	fuel_per_square = (int)(FULL_FUEL/METER_ELEMENT_NUM); //燃料メーター■１つあたりの燃料量

	for(int i = 0; i < (METER_ELEMENT_NUM * 2); i++){ //■は２バイトなので処理を倍に
		if ((count_fuel - 4) < fuel) //何故か"-4"を付けないとうまくいってくんない
			meter[i] = full_fuel[i];
		else
			meter[i] = empty_fuel[i];

		//このままではfuel_per_squareが奇数の場合マズイ！
		count_fuel += (int)(fuel_per_square / 2);
	}
	for (int j = 0; j < (METER_ELEMENT_NUM * 2); j++)
		cout << meter[j];
}

void car::move_car(void)
{
		rest_distance--;  //距離１に対し
		fuel--;           //燃料１の消費

		cout << "残りの距離：" << rest_distance <<"　残りの燃料："<< fuel <<"  ";

		if (rest_distance == 0){
			cout <<"到着しました"<<"\n";
			exit(0);
		}else if(fuel == 0){
			cout<<"燃料切れです"<<"\n";
			exit(0);
		}
}

int main(int, char**)
{
	int counter = 0;
	car impreza;
	while (!_kbhit()){ //キー入力によりループ脱出

		if (!(counter % WAIT)){    //時間稼ぎ

			cout << "\x1b[5;5H" <<"\x1b[>5h"; //画面表示の処理

			impreza.set_meter();
			impreza.move_car();
		}

		counter++;
	}

	return 0;
}
