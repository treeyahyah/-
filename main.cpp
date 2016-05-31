#include<iostream>

using namespace std;

enum {
	weekdays = 0,
	holiday,
};

struct Price{
	int adult;
	int child;
};


void main(){
	Price price[2];	//價錢設定(平日, 晚上假日)
	price[weekdays].adult = 268;
	price[weekdays].child = 120;
	price[holiday].adult = 368;
	price[holiday].child = 150;
	int mode = 0;		//紀錄平日或晚上假日
	int adult = 0;		//大人和小孩的人數
	int child = 0;
	cout << "平日中午:0 or 平日晚間/假日:1" << endl;
	cin >> mode;
	cout << "請輸入大人人數: ";
	cin >> adult;
	cout << "請輸入小孩人數: ";
	cin >> child;

	int totalPeople = adult + child;		//總人數
	int free = totalPeople/3;				//免費人數

	//扣掉免費的人
	if(free != 0){
		if(child >= free){
			child -= free;			//小孩免費
		}
		else{
			free -= child;			//減掉小孩的人數
			child = 0;
			adult -=free;			//在減掉大人(剩下多人人需要錢)
		}
	}

	//計算價錢
	int total =( (adult * price[mode].adult) + (child * price[mode].child))*1.1;

	//如果有超過10人以上打9.5折
	if(totalPeople >= 10){
		total = total * 0.95;
	}

	cout << "總金額為: " << total << endl;

	system("pause");
}
