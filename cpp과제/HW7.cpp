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

void input(Goods& s);                     //�Է�
void seling_price(Goods& s);              //������ ���
void prn(const Goods& s);                 //���
int tot_day(int y ,int m, int d);         //�� �ϼ� ���
int leap_check(int year);                 //���� ���
int monthCheck(int year, int month);      //�� ���  
void getdate(struct date* p);             //���� ��¥ ���

int main() {
    Goods goods;
    
    input(goods);         //�Է�
    seling_price(goods);  //���ο� ���
    prn(goods);           //���
   
    return 0;
}

void input(Goods& s) {
    cout << "ǰ�� �Է� : ";
    cin.getline(s.item, sizeof(s.item));
    cout << "���� �Է� : ";
    cin >> s.price;
    cout << "������� �Է� : ";
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
    cout << "ǰ�� : " << s.item << endl;
    
    if (s.discount == -1) { 
        cout << "��������� �������ϴ�!" << endl; 
        cout << "������� : " << s.year << "-" << s.mon << "-" << s.day << endl;
    }
    else {
        cout << "�ǸŰ� : " << s.price - s.price * (s.discount*0.01) << endl;
        cout << "������� : " << s.year << "-" << s.mon << "-" << s.day << endl;
        cout << "������ : " << s.discount << "%" << endl;
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
int leap_check(int year) {  // �����̸� 1, ����̸� 0 ����
    if (year % 4 != 0) { // 4�� ������ �������� ������ ���
        return 0;
    }
    else if (year % 100 != 0) { // 4�� ������ �������� 100���� ������ �������� ������ ����
        return 1;
    }
    else if (year % 400 == 0) { // 4�� 100�� 400���� ������ �������� ����
        return 1;
    }
    else { // 4�� 100���� ������ �������� 400���� ������ �������� ������ ���
        return 0;
    }
}
int monthCheck(int year, int month) {
    if (month == 2) {
        if (year == 0) { return 28; } //���
        else { return 29; } //����
    }
    else {
        if (month >= 8) {//8�� ����
            if (month % 2 == 0) { return 31; } //8�� ���� ¦�� �� - 31�ϱ���
            else { return 30; } //8�� ���� Ȧ�� �� - 30�ϱ���
        }
        else {
            if (month % 2 == 0) { return 30; } //8�� ���� ¦�� �� - 30�ϱ���
            else { return 31; } //8�� ���� Ȧ�� �� - 31�ϱ���
        }
    }
}

void getdate(struct date* p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ��� 
{
    char temp[128];
    char* cp, syear[5] = "20";
    _strdate(temp); // temp char�迭 �ȿ� 08/10/04(��/��/��)������ ������� ���ڿ� ���·� ���� 
    cp = strtok(temp, "/"); // temp�迭�� ù��° '/'���� ���ڿ��� ����� cp���� "08" ���ڿ��� �����ּҸ� ���� 
    p->da_mon = atoi(cp); // ��� "08"���ڿ��� ������ ������ 8�� ��ȯ�Ͽ� p->da_mon�� ���� 
    cp = strtok(NULL, "/"); // temp�迭�� �ι�° '/'���� ���ڿ��� ����� cp���� "10" ���ڿ��� �����ּҸ� ���� 
    p->da_day = atoi(cp); // ��� "10"���ڿ��� ������ ������ 10�� ��ȯ�Ͽ� p->da_day�� ���� 
    cp = strtok(NULL, "/"); // temp�迭�� ����° '/'���� ���ڿ��� ������ϳ� '/'�� ��Ÿ���� �ʰ� ���ڿ��� 
                            // ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� "04" ���ڿ��� �����ּҰ� �����Ѵ�. 
    strcat(syear, cp); // syear���� "20"�� cp�� ����Ű�� "04"�� �ٿ��� "2004" ���ڿ��� syear������ ���� 
    p->da_year = atoi(syear); // syear���� "2004" ���ڿ��� ������ ������ 2004�� ��ȯ�Ͽ� p->da_year�� ���� 
}