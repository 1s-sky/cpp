#include <iostream>
#include "SmartArray.h"
using namespace std;

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray cheoli(3);
	SmartArray metel(5);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;
	//ö��
	cout << "ö���� �� ������ ���� �Է� : ";
	for (i = 0; i < 3; i++) {
		cin >> temp;
		if (cheoli.put(i, temp) == false)
		{
			cout << "�迭 ���� ����" << endl;
		}
	}

	for (i = 0; i < 3; i++) {
		res = cheoli.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "�迭 �б� ����" << endl;
		}
	}
	cout << "���� : " << tot << endl;
	cout << "��� : " << tot / 3.0 << endl;

	tot = 0;
	//����
	cout << "������ �ټ� ������ ���� �Է� : ";
	for (i = 0; i < 5; i++) {
		cin >> temp;
		if (metel.put(i, temp) == false)
		{
			cout << "�迭 ���� ����" << endl;
		}
	}

	for (i = 0; i < 5; i++) {
		res = metel.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "�迭 �б� ����" << endl;
		}
	}
	cout << "���� : " << tot << endl;
	cout << "��� : " << tot / 5.0 << endl;

	if (cheoli > metel) { cout << "������ �ְ����� ö�̺��� ũ�� �ʴ�..." << endl; }
	else { cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�..." << endl; }
	return 0;
}