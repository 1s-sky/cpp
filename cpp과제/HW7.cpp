#include <iostream>
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
void input(Goods& s);
void seling_price(Goods& s);
void prn(const Goods& s);
int tot_day(int y ,int m, int d);
int leap_check(int year);

int main() {

}

void input(Goods& s);
void seling_price(Goods& s);
void prn(const Goods& s);
int tot_day(int y, int m, int d);
int leap_check(int year);