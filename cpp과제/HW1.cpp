#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int math, kor, eng, sum;
	char name[20];

	cout << "�̸� : ";
	cin.getline(name, sizeof(name));

	cout << "�� ������ ���� : ";
	cin >> kor >> eng >> math;

	sum = kor + eng + math;

	cout << "\n\t\t\t\b\b\b\b=====< ����ǥ >====="<<endl;
	cout << "============================================================"<<endl;
	cout << right;
	cout << setw(10) << "�̸�" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "���" << endl;
	cout << "============================================================" << endl;
	cout << setprecision(4);
	cout << setw(10) << name << setw(10) << kor << setw(10) << eng << setw(10) << math << setw(10) << sum << setw(10) << sum / 3.0 << endl;
	return 0;
}