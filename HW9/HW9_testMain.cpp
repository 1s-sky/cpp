#include <iostream>
#include "Robot.h"
#pragma warning (disable : 4996)
using namespace std;

//응옹프로그램에서 사용하는 함수들
void input(int& cnt);
void input(Robot* rp, int cnt);
void work(Robot* rp, int cnt);
void workNum(Robot* rp, int i);
void prn(Robot* rp, int cnt);
void myflush();

//이름 잘못되면 재입력 요구
//종료조건 : end 
int main() {
	int cnt;      //로봇의 대수 저장변수
	Robot* rp;
	input(cnt);   //로봇의 대수 입력합수

	rp = new Robot[cnt];  //로봇 객체배열 동적할당

	input(rp, cnt);    //로봇명과 에너지 양 입력함수

	work(rp, cnt);     //로봇 일시키기 함수

	prn(rp, cnt);      //로봇명과 에너지 출력함수

	delete[] rp;
	return 0;
}
void input(int& cnt) {
	cout << "구입할 로봇 대수를 입력하시오 : ";
	cin >> cnt;
}
void input(Robot* rp, int cnt) {
	char str[100];
	int energy;
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "번 로봇명을 입력하시오 : ";
		cin >> str;
		rp[i].setName(str);
		cout << rp[i].getName() << "의 에너지 양을 입력하시오 : ";
		cin >> energy;
		rp[i].setEnergy(energy);
		cout << endl;
	}
}
void work(Robot* rp, int cnt) {
	char rname[100];
	while (1) {
		cout << "# 로봇명 선택(";
		for (int i = 0; i < cnt; i++) {
			cout << rp[i].getName() <<", ";
		}
		cout << "\b\b) : ";
		cin >> rname;
		if (strcmp(rname, "end") == 0) { break; } //종료 조건

		for (int i = 0; i < cnt; i++) {
			if (strcmp(rname, rp[i].getName()) == 0) {
				workNum(rp, i);
			}
		}
		cout << endl;
	}
}
void workNum(Robot* rp, int i) {
	int num;
	int energy;
	//번호선택
	cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
	cin >> num;
	while (num <= 0 || num > 5 || cin.get() != '\n') {
		myflush();
		cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
		cin >> num;
	}
	//동작
	if (num == 1) rp[i].go();
	else if (num == 2) rp[i].back();
	else if (num == 3) rp[i].turn();
	else if (num == 4) rp[i].jump();
	else {
		cout << "충전할 에너지양 입력 : ";
		cin >> energy;
		if (energy < 0) energy = 0;
		cout << rp[i].getName() << "에너지 " << energy << " 충전";
		rp[i].charge(energy);
	}
}
void prn(Robot* rp, int cnt) {
	cout << endl;
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << ". " << rp[i].getName() << " : " << rp[i].getEnergy() << endl;
	}
}
void myflush(){
	cin.clear();
	while (cin.get() != '\n') { ; }
}