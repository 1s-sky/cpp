#include <iostream>
#include <time.h> 
#include<windows.h> 
#pragma warning (disable : 4996)
using namespace std;

struct Goods
{
	char item[50];
	int price;
	int year;
	int mon;
	int day;
	int discount;
};

struct date {
    unsigned int da_year;
    unsigned int da_mon;
    unsigned int da_day;
};

void input(Goods& s);                     //입력
void seling_price(Goods& s);              //할인율 계산
void prn(const Goods& s);                 //출력
int tot_day(int y ,int m, int d);         //총 일수 계산
int leap_check(int year);                 //윤년 계산
int monthCheck(int year, int month);      //달 계산  
void getdate(struct date* p);             //현재 날짜 계산

int main() {
    Goods goods;
    
    input(goods);         //입력
    seling_price(goods);  //할인울 계산
    prn(goods);           //출력
   
    return 0;
}

void input(Goods& s) {
    cout << "품목 입력 : ";
    cin.getline(s.item, sizeof(s.item));
    cout << "정가 입력 : ";
    cin >> s.price;
    cout << "유통기한 입력 : ";
    cin >> s.year >> s.mon >> s.day;
}

void seling_price(Goods& s) {
    struct date stdate;
    int tot_sell_day;
    int tot_now;
    int remain_day;

    tot_sell_day = tot_day(s.year, s.mon, s.day);
    getdate(&stdate);
    tot_now = tot_day(stdate.da_year, stdate.da_mon, stdate.da_day);
    remain_day = tot_sell_day - tot_now;
    if (remain_day < 0) s.discount = -1;
    else if (remain_day <= 3) s.discount = 50;
    else if (remain_day <= 10) s.discount = 20;
    else s.discount = 0;
    return;
}

void prn(const Goods& s) {
    cout << "품명 : " << s.item << endl;
    
    if (s.discount == -1) { 
        cout << "유통기한이 지났습니다!" << endl; 
        cout << "유통기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
    }
    else {
        cout << "판매가 : " << s.price - s.price * (s.discount*0.01) << endl;
        cout << "유통기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
        cout << "할인율 : " << s.discount << "%" << endl;
    }
}

int tot_day(int y, int m, int d) {
    int td = 0;
    int ycheck;
    for (int i = 1900; i < y; i++) {
        ycheck = leap_check(i);
        td += (365 + ycheck);
    }
    for (int i = 1; i < m; i++) {
        ycheck = leap_check(y);
        td += monthCheck(ycheck, i);
    }
    td += d;
    return td;
}
int leap_check(int year) {  // 윤년이면 1, 평년이면 0 리턴
    if (year % 4 != 0) { // 4로 나누어 떨어지지 않으면 평년
        return 0;
    }
    else if (year % 100 != 0) { // 4로 나누어 떨어지고 100으로 나누어 떨어지지 않으면 윤년
        return 1;
    }
    else if (year % 400 == 0) { // 4와 100과 400으로 나누어 떨어지면 윤년
        return 1;
    }
    else { // 4와 100으로 나누어 떨어지고 400으로 나누어 떨어지지 않으면 평년
        return 0;
    }
}
int monthCheck(int year, int month) {
    if (month == 2) {
        if (year == 0) { return 28; } //평년
        else { return 29; } //윤년
    }
    else {
        if (month >= 8) {//8월 이후
            if (month % 2 == 0) { return 31; } //8월 이후 짝수 달 - 31일까지
            else { return 30; } //8월 이후 홀수 달 - 30일까지
        }
        else {
            if (month % 2 == 0) { return 30; } //8월 이전 짝수 달 - 30일까지
            else { return 31; } //8월 이전 홀수 달 - 31일까지
        }
    }
}

void getdate(struct date* p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용 
{
    char temp[128];
    char* cp, syear[5] = "20";
    _strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장 
    cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴 
    p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장 
    cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴 
    p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장 
    cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이 
                            // 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다. 
    strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장 
    p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장 
}