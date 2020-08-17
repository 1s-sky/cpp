#include <iostream>
#include "SmartArray.h"
using namespace std;

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray cheoli(3);
	SmartArray metel(5);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;
	//철이
	cout << "철이의 세 과목의 점수 입력 : ";
	for (i = 0; i < 3; i++) {
		cin >> temp;
		if (cheoli.put(i, temp) == false)
		{
			cout << "배열 쓰기 실패" << endl;
		}
	}

	for (i = 0; i < 3; i++) {
		res = cheoli.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "배열 읽기 실패" << endl;
		}
	}
	cout << "총점 : " << tot << endl;
	cout << "평균 : " << tot / 3.0 << endl;

	tot = 0;
	//메텔
	cout << "메텔의 다섯 과목의 점수 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> temp;
		if (metel.put(i, temp) == false)
		{
			cout << "배열 쓰기 실패" << endl;
		}
	}

	for (i = 0; i < 5; i++) {
		res = metel.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "배열 읽기 실패" << endl;
		}
	}
	cout << "총점 : " << tot << endl;
	cout << "평균 : " << tot / 5.0 << endl;

	if (cheoli > metel) { cout << "메텔의 최고점은 철이보다 크지 않다..." << endl; }
	else { cout << "철이의 최고점은 메텔보다 크지 않다..." << endl; }
	return 0;
}