#include <iostream>
#include "Robot.h"
#pragma warning (disable : 4996)
using namespace std;

//�������α׷����� ����ϴ� �Լ���
void input(int& cnt);
void input(Robot* rp, int cnt);
void work(Robot* rp, int cnt);
void workNum(Robot* rp, int i);
void prn(Robot* rp, int cnt);
void myflush();

//�̸� �߸��Ǹ� ���Է� �䱸
//�������� : end 
int main() {
	int cnt;      //�κ��� ��� ���庯��
	Robot* rp;
	input(cnt);   //�κ��� ��� �Է��ռ�

	rp = new Robot[cnt];  //�κ� ��ü�迭 �����Ҵ�

	input(rp, cnt);    //�κ���� ������ �� �Է��Լ�

	work(rp, cnt);     //�κ� �Ͻ�Ű�� �Լ�

	prn(rp, cnt);      //�κ���� ������ ����Լ�

	delete[] rp;
	return 0;
}
void input(int& cnt) {
	cout << "������ �κ� ����� �Է��Ͻÿ� : ";
	cin >> cnt;
}
void input(Robot* rp, int cnt) {
	char str[100];
	int energy;
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "�� �κ����� �Է��Ͻÿ� : ";
		cin >> str;
		rp[i].setName(str);
		cout << rp[i].getName() << "�� ������ ���� �Է��Ͻÿ� : ";
		cin >> energy;
		rp[i].setEnergy(energy);
		cout << endl;
	}
}
void work(Robot* rp, int cnt) {
	char rname[100];
	while (1) {
		cout << "# �κ��� ����(";
		for (int i = 0; i < cnt; i++) {
			cout << rp[i].getName() <<", ";
		}
		cout << "\b\b) : ";
		cin >> rname;
		if (strcmp(rname, "end") == 0) { break; } //���� ����

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
	//��ȣ����
	cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
	cin >> num;
	while (num <= 0 || num > 5 || cin.get() != '\n') {
		myflush();
		cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
		cin >> num;
	}
	//����
	if (num == 1) rp[i].go();
	else if (num == 2) rp[i].back();
	else if (num == 3) rp[i].turn();
	else if (num == 4) rp[i].jump();
	else {
		cout << "������ �������� �Է� : ";
		cin >> energy;
		if (energy < 0) energy = 0;
		cout << rp[i].getName() << "������ " << energy << " ����";
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