#include <iostream>
using namespace std;

void swap_ptr(const char*&, const char*&);
int main() {
	const char* ap = "apple";
	const char* bp = "banana";

	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl << endl;
	swap_ptr(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
	return 0;
}

void swap_ptr(const char*& str1, const char*& str2) {
	const char* temp = str1;
	str1 = str2;
	str2 = temp;
	return;
}