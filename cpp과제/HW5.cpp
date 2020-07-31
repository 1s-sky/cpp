#include <iostream>
using namespace std;
struct Savings
{
	int w500;
	int w100;
	int w50;
	int w10;
};
void init(Savings& s);
void input(int& unit, int& cnt);
void save(Savings& s, int unit, int cnt);
int total(Savings& s);
void myflush();

int main() {
	Savings s;
	int unit, cnt;

	init(s);
	input(unit, cnt);
	save(s, unit, cnt);
	while (unit >= 0) {
		input(unit, cnt);
		save(s, unit, cnt);
	}
	cout << "총 저금액 : " << total(s);
}

void init(Savings& s) {
	s.w500 = s.w100 = s.w50 = s.w10 = 0;
}
void input(int& unit, int& cnt) {
	cout << "동전의 금액 : ";
	cin >> unit;
	if (unit < 0) return;
	while ((unit != 500 && unit != 100 && unit != 50 && unit !=10) || cin.get() != '\n') {
		myflush();
		cout << "동전의 금액 : ";
		cin >> unit;
	}
	cout << "동전의 개수 : ";
	cin >> cnt;
	while (cnt < 0 || cin.get() != '\n') {
		myflush();
		cout << "동전의 개수 : ";
		cin >> cnt;
	}
	return;
}
void save(Savings& s, int unit, int cnt) {
	switch (unit)
	{
	case 500: s.w500 += cnt; break;
	case 100: s.w100 += cnt; break;
	case 50: s.w50 += cnt; break;
	case 10: s.w10 += cnt; break;
	default:
		break;
	}
}
int total(Savings& s) {
	int tot = s.w500 * 500 + s.w100 * 100 + s.w50 * 50 + s.w10 * 10;
	return tot;
}
void myflush() {
	cin.clear();
	while (cin.get() != '\n') { ; }
}