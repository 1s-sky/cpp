#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time();                 //0시 0분으로 초기화
	Time(int hour, int min);
	Time(double time);
	Time(const Time& str);  //복사 생성자
	Time plus(const Time& tr);
	void setHour(int hour);
	int getHour();
	void setMin(int min);
	int getMin();
};

Time::Time() { //0시 0분으로 초기화
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
Time::Time(const Time& str){  //복사 생성자
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
	cout << a.getHour() << "시간 " << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간 " << b.getMin() << "분" << endl;
	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간 " << res.getMin() << "분" << endl;
	cout << a.getHour() << "시간 " << a.getMin() << "분" << endl;
	cout << b.getHour() << "시간 " << b.getMin() << "분" << endl;
	return 0;
}