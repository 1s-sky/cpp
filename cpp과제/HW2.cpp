#include <iostream>
#include <cstring>
using namespace std;

double max(double, double);
char* max(char*, char*);

int main() {
	double a, b;
	char str1[100], str2[100];

	cout << "�� �Ǽ� �Է� : ";
	cin >> a >> b;
	cout << "ū �� : " << max(a, b) << endl;
	cout << "�� ���ڿ� �Է� : ";
	cin >> str1 >> str2;
	cout << "�� ���ڿ� : " << max(str1, str2) << endl;
	return 0;
}

double max(double a, double b) {   //�� ū ���� ����
	if (a > b) return a;
	else return b;
}

char* max(char* str1, char* str2) {                 //���̰� �� �� ����
	if (strlen(str1) >= strlen(str2)) return str1;  //���̰� ������ ù ��° ���ڿ��� �����Ѵ�       
	else  return str2;

}