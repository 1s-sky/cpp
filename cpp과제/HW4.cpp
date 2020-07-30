#include <iostream>
using namespace std;

int length(char*, char = '\0');
int main() {
	char str[100], ch;

	cout << "문자열 입력 : ";
	cin >> str;
	cout << "문자열의 길이 : " << length(str) << endl;
	
	cout << "문자 입력 : ";
	cin >> ch;
	cout << ch << " 이전 까지의 길이 : " << length(str, ch) << endl;
	return 0;
}

int length(char* str, char ch) {   //문자열에 문자가 포함되어 있지 않을 경우 총 길리 리턴
	int count = 0;
	while (*str != ch && *str != '\0') {
		str++;
		count++;
	}
	return count;
}