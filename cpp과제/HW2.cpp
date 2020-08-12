#include <iostream>
#include <cstring>
using namespace std;

double max(double, double);
char* max(char*, char*);

int main() {
	double a, b;
	char str1[100], str2[100];

	cout << "두 실수 입력 : ";
	cin >> a >> b;
	cout << "큰 값 : " << max(a, b) << endl;
	cout << "두 문자열 입력 : ";
	cin >> str1 >> str2;
	cout << "긴 문자열 : " << max(str1, str2) << endl;
	return 0;
}

double max(double a, double b) {   //더 큰 수를 리턴
	if (a > b) return a;
	else return b;
}

char* max(char* str1, char* str2) {                 //길이가 긴 것 리턴
	if (strlen(str1) >= strlen(str2)) return str1;  //길이가 같으면 첫 번째 문자열을 리턴한다       
	else  return str2;

}