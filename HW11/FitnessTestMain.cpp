#include <iostream>
#include "Fitness.h"
#pragma warning (disable : 4996)
using namespace std;

int menu();
void signUp(Fitness**, int&, int&);
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
			cout << "/회원등록 메뉴입니다-----------------------------" << endl;
			signUp(fary, memberCnt, memberNum); 
			break;
		case 2: 
			cout << "/회원출력 메뉴입니다-----------------------------" << endl;
			for (int i = 0; i < memberCnt; i++) {
				prn(fary, i);
			}
			break;
		case 3:
			cout << "/회원검색 메뉴입니다-----------------------------" << endl; 
			search(fary, memberCnt); 
			break;
		case 4: 

			cout << "/회원탈퇴 메뉴입니다-----------------------------" << endl; 
			withdraw(fary, memberCnt); 
			break;
		case 5: 
			cout << "/특별회원 메뉴입니다-----------------------------" << endl; 
			special(fary, memberCnt); 
			break;
		}
		cout << endl;
	}

	//종료 시 모든 객체  free
	for (int i = 0; i < memberCnt; i++)	{ delete fary[i]; }

	return 0;
}

int menu()
{
	int menu;
	cout << "* 메뉴 선택(1,회원등록 / 2,회원전체보기 / 3,회원정보검색 / 4,회원탈퇴 / 5,특별관리회원 / 6,종료) : ";
	cin >> menu;

	while (menu < 1 || menu > 6)
	{
		cout << "* 메뉴 선택(1,회원등록 / 2,회원전체보기 / 3,회원정보검색 / 4,회원탈퇴 / 5,특별관리회원 / 6,종료) : ";;
		cin >> menu;
	}
	return menu;
}

void signUp(Fitness** fary, int& memberCnt, int& memberNum) 
{
	char name[100];
	double weight;
	double height;
	
	cout << "이름을 입력해주세요 : ";
	cin >> name;
	cout << "몸무게를 입력해주세요(kg) : ";
	cin >> weight;
	cout << "키를 입력해주세요(cm) : ";
	cin >> height;

	fary[memberCnt] = new Fitness(memberNum, name, weight, height);
	memberNum++;
	memberCnt++;
}
void prn(Fitness** fary, int i)
{
	cout << "회원번호 : " << fary[i]->getNum() << " / 회원명 : " << fary[i]->getName() 
		<< " / 몸무게 : " << fary[i]->getWeight() << " / 키 : " << fary[i]->getHeight() << endl;	
}
void search(Fitness** fary, int memberCnt)
{
	char name[100];
	cout << "검색할 이름을 입력하세요 : ";
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
	cout << "탈퇴할 회원의 회원번호를 입력해주세요 : ";
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
	cout << "<고도비만>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() >= 40.0) {
			prn(fary, i);
		}
	}
	cout << "<비만>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() < 40.0 && fary[i]->bmi() >= 30.0) {
			prn(fary, i);
		}
	}
	cout << "<과체중>" << endl;
	for (int i = 0; i < memberCnt; i++)
	{
		if (fary[i]->bmi() < 30.0 && fary[i]->bmi() >= 25.0) {
			prn(fary, i);
		}
	}
}
