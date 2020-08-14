#include <iostream>
#include "MyString.h"
#pragma warning (disable : 4996)
using namespace std;

int main()
{
	MyString ary[5];
	MyString res;

	int i;
	cout << "5���� �����̸� �Է� :";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];   //�Է¿����� ���
	}
	cout << "ù��°�� �ι�° �� �� ���� �̸� :";
	if (ary[0] > ary[1]) {
		cout << ary[0] << endl;   //��¿����� ���
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	cout << "��� ���ڿ� ��� : " << res << endl;
	cout << "�迭���� ���ڿ� ���..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}

	return 0;
}

ostream& operator<<(ostream& os, MyString& br)
{
	os << br.str << "(" << br.len << ")";
	return os;
}
istream& operator>>(istream& is, MyString& br)
{
	char str[100];
	if (br.str != NULL) { delete[] br.str; }
	is >> str;
	br.str = new char[strlen(str) + 1];
	strcpy(br.str, str);
	br.len = strlen(br.str);
	return is;
}

//
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

class Time
{
private:
	int hour;
	int min;
	double time;
	static int mode;
	enum { integer, real };
public:
	Time();
	Time(int, int);
	Time(double);
	Time plus(const Time& tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	friend ostream& operator<<(ostream& os, const Time& br);
	static void mode_change();
};

int Time::mode = Time::integer;

Time::Time()
{
	this->hour = 0;
	this->min = 0;
	this->time = 0;
}
Time::Time(int hour, int min)
{
	this->hour = hour;
	this->min = min;
	this->time = hour + min / 60.0;
}
Time::Time(double time)
{
	this->hour = (int)time;
	this->min = (time - (int)time) * 60;
	this->time = time;
}
Time Time::plus(const Time& tr)
{
	Time res;
	res.time = this->time + tr.time;
	res.hour = this->hour + tr.hour;
	res.min = this->min + tr.min;
	if (res.min >= 60) {
		res.hour++;
		res.min = res.min % 60;
	}
	return res;
}
void Time::setHour(int hour)
{
	this->hour = hour;
}
int Time::getHour()
{
	return this->hour;
}
void Time::setMin(int min)
{
	this->min = min;
}
int Time::getMin()
{
	return this->min;
}
ostream& operator<<(ostream& os, const Time& br)
{
	if (Time::mode == Time::integer) {
		cout << br.hour << "�ð� " << br.min << "��";
	}
	else {
		cout << br.time << "�ð�";
	}
	return os;
}
void Time::mode_change()
{
	if (mode == integer) mode = real;
	else mode = integer;
}

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "�⺻ ��� ����(�ð�, ��)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "��¸�带 �ٲ� ��..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}