#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time();                 //0�� 0������ �ʱ�ȭ
	Time(int hour, int min);
	Time(double time);
	Time(const Time& str);  //���� ������
	Time plus(const Time& tr);
	void setHour(int hour);
	int getHour();
	void setMin(int min);
	int getMin();
};

Time::Time() { //0�� 0������ �ʱ�ȭ
	this->hour = 0;
	this->min = 0;
}
Time::Time(int hour, int min) {
	this->hour = hour;
	if (min < 60)	this->min = min;
	else this->min = min - 60;
}
Time::Time(double time) {
	this->hour = (int)time;
	this->min = (int)((time - (int)time) * 60);
}
Time::Time(const Time& str){  //���� ������
	this->hour = str.hour;
	this->min = str.min;
}
Time Time::plus(const Time& tr) {
	Time res;
	res.hour = this->hour + tr.hour;
	res.min = this->min + tr.min;
	if (res.min >= 60) {
		res.hour++;
		res.min = res.min - 60;
	}
	return res;
}
void Time::setHour(int hour) {
	this->hour = hour;
}
int Time::getHour() {
	return this->hour;
}
void Time::setMin(int min) {
	if (min < 60)	this->min = min;
	else this->min = min - 60;
}
int Time::getMin() {
	return this->min;
}

int main() {
	Time a(3, 20), b;
	cout << a.getHour() << "�ð� " << a.getMin() << "��" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð� " << b.getMin() << "��" << endl;
	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð� " << res.getMin() << "��" << endl;
	cout << a.getHour() << "�ð� " << a.getMin() << "��" << endl;
	cout << b.getHour() << "�ð� " << b.getMin() << "��" << endl;
	return 0;
}