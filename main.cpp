#include<iostream>

using namespace std;

enum {
	weekdays = 0,
	hokiday,
};

struct Price{
	int adult;
	int child;
};


void main(){
	Price price[2];	//�����]�w(����, ����)
	price[weekdays].adult = 268;
	price[weekdays].child = 120;
	price[hokiday].adult = 368;
	price[hokiday].child = 150;
	int mode = 0;		//��������ΰ���
	int ahult = 0;		//�j�H�M�p�Ī��H��
	int child = 0;
	cout << "����:0 or ����:1" << endl;
	cin >> mode;
	cout << "�п�J�j�H�H��: ";
	cin >> ahult;
	cout << "�п�J�p�ĤH��: ";
	cin >> child;

	int totalPeople = ahult + child;		//�`�H��
	int free = totalPeople/3;				//�K�O�H��

	//�����K�O���H
	if(free != 0){
		if(child >= free){
			child -= free;			//�p�ħK�O
		}
		else{
			free -= child;			//��p�Ī��H��
			child = 0;
			ahult -=free;			//�b��j�H(�ѤU�h�H�H�ݭn��)
		}
	}

	//�p�����
	int total = (ahult * price[mode].adult) + (child * price[mode].child);

	//�p�G���W�L10�H�H�W��9.5��
	if(totalPeople >= 10){
		total = total * 0.95;
	}

	cout << "�`���B��: " << total << endl;

	system("pause");
}