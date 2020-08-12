#include <iostream>
#include "Fitness.h"
#pragma warning (disable : 4996)
using namespace std;

int menu();
void signIn(Fitness**, int&, int&);
void prn(Fitness**, int);
void search(Fitness**, int);
void withdraw(Fitness**, int&);
void special(Fitness**, int);


int main() 
{
	Fitness* fary[100];
	int memberCnt = 0;
	int memberNum = 0;
	int menuNum;

	while (1)
	{
		menuNum = menu();
		if (menuNum == 6) break;
		switch (menuNum)
		{
		case 1: 
			cout << "/ȸ����� �޴��Դϴ�-----------------------------" << endl;
			signIn(fary, memberCnt, memberNum); 
			break;
		case 2: 
			cout << "/ȸ����� �޴��Դϴ�-----------------------------" << endl;
			for (int i = 0; i < memberCnt; i++) {
				prn(fary, i);
			}
			break;
		case 3:
			cout << "/ȸ���˻� �޴��Դϴ�-----------------------------" << endl; 
			search(fary, memberCnt); 
			break;
		case 4: 

			cout << "/ȸ��Ż�� �޴��Դϴ�-----------------------------" << endl; 
			withdraw(fary, memberCnt); 
			break;
		case 5: 
			cout << "/Ư��ȸ�� �޴��Դϴ�-----------------------------" << endl; 
			special(fary, memberCnt); 
			break;
		}
		cout << endl;
	}

	//���� �� ��� ��ü  free
	for (int i = 0; i < memberCnt; i++)	{ delete fary[i]; }

	return 0;
}

int menu()
{
	int menu;
	cout << "* �޴� ����(1,ȸ����� / 2,ȸ����ü���� / 3,ȸ�������˻� / 4,ȸ��Ż�� / 5,Ư������ȸ�� / 6,����) : ";
	cin >> menu;

	while (menu < 1 || menu > 6)
	{
		cout << "* �޴� ����(1,ȸ����� / 2,ȸ����ü���� / 3,ȸ�������˻� / 4,ȸ��Ż�� / 5,Ư������ȸ�� / 6,����) : ";;
		cin >> menu;
	}
	return menu;
}

void signIn(Fitness** fary, int& memberCnt, int& memberNum) 
{
	char name[100];
	double weight;
	double height;
	
	cout << "�̸��� �Է����ּ��� : ";
	cin >> name;
	cout << "�����Ը� �Է����ּ���(kg) : ";
	cin >> weight;
	cout << "Ű�� �Է����ּ���(cm) : ";
	cin >> height;

	fary[memberCnt] = new Fitness(memberNum, name, weight, height);
	memberNum++;
	memberCnt++;
}
void prn(Fitness** fary, int i)
{
	cout << "ȸ����ȣ : " << fary[i]->getNum() << " / ȸ���� : " << fary[i]->getName() 
		<< " / ������ : " << fary[i]->getWeight() << " / Ű : " << fary[i]->getHeight() << endl;	
}
void search(Fitness** fary, int memberCnt)
{
	char name[100];
	cout << "�˻��� �̸��� �Է��ϼ��� : ";
	cin >> name;
	for (int i = 0; i < memberCnt; i++)
	{
		if (strcmp(fary[i]->getName(), name) == 0) {
			prn(fary, i);
		}
	}
}
void withdraw(Fitness** fary, int& memberCnt)
{
	int num;
	int i;
	cout << "Ż���� ȸ���� ȸ����ȣ�� �Է����ּ��� : ";
	cin >> num;
	for (i = 0; i < memberCnt; i++)
	{
		if (num == fary[i]->getNum()) {
			delete fary[i];
			memberCnt--;
			break;
		}
	}
	for (int j = i; j < memberCnt ; j++)
	{
		fary[j] = fary[j + 1];
	}
}
void special(Fitness** fary, int memberCnt)
{
	cout << "<����>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() >= 40.0) {
			prn(fary, i);
		}
	}
	cout << "<��>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() < 40.0 && fary[i]->bmi() >= 30.0) {
			prn(fary, i);
		}
	}
	cout << "<��ü��>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() < 30.0 && fary[i]->bmi() >= 25.0) {
			prn(fary, i);
		}
	}
}