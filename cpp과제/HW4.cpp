#include <iostream>
using namespace std;

int length(char*, char = '\0');
int main() {
	char str[100], ch;

	cout << "���ڿ� �Է� : ";
	cin >> str;
	cout << "���ڿ��� ���� : " << length(str) << endl;
	
	cout << "���� �Է� : ";
	cin >> ch;
	cout << ch << " ���� ������ ���� : " << length(str, ch) << endl;
	return 0;
}

int length(char* str, char ch) {   //���ڿ��� ���ڰ� ���ԵǾ� ���� ���� ��� �� �渮 ����
	int count = 0;
	while (*str != ch && *str != '\0') {
		str++;
		count++;
	}
	return count;
}