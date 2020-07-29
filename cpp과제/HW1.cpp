#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int math, kor, eng, sum;
	char name[20];

	cout << "이름 : ";
	cin.getline(name, sizeof(name));

	cout << "세 과목의 점수 : ";
	cin >> kor >> eng >> math;

	sum = kor + eng + math;

	cout << "\n\t\t\t\b\b\b\b=====< 성적표 >====="<<endl;
	cout << "============================================================"<<endl;
	cout << right;
	cout << setw(10) << "이름" << setw(10) << "국어" << setw(10) << "영어" << setw(10) << "수학" << setw(10) << "총점" << setw(10) << "평균" << endl;
	cout << "============================================================" << endl;
	cout << setprecision(4);
	cout << setw(10) << name << setw(10) << kor << setw(10) << eng << setw(10) << math << setw(10) << sum << setw(10) << sum / 3.0 << endl;
	return 0;
}