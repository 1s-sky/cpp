#include "Save.h"
#pragma warning (disable : 4996)

double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;
Save::Save(const char* np, int n)
{
	strcpy(this->name, np);
	this->capital = n;
	this->profit = 0;
	this->tax = 0;
	this->tot = 0;
}
void Save::calculate()
{
	this->profit = this->capital * ratio;
	this->tax = this->profit * tax_ratio;
	this->tot = this->capital + this->profit - this->tax;
}
ostream& operator<<(ostream& os, const Save& br)
{
	os << "이름 : " << br.name << endl;
	os << "원금 : " << br.capital << endl;
	os << "이자소득 : " << br.profit << endl;
	os << "세금 : " << br.tax << endl;
	os << "총금액 : " << br.tot << endl;
	os << "이율 : " << br.ratio << endl;
	os << "세율 : " << br.tax_ratio << endl;
	return os;
}
void Save::set_ratio(double r)
{
	ratio = r;
}