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
		cout << br.hour << "시간 " << br.min << "분";
	}
	else {
		cout << br.time << "시간";
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
	cout << "기본 출력 형태(시간, 분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}