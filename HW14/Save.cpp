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
	os << "�̸� : " << br.name << endl;
	os << "���� : " << br.capital << endl;
	os << "���ڼҵ� : " << br.profit << endl;
	os << "���� : " << br.tax << endl;
	os << "�ѱݾ� : " << br.tot << endl;
	os << "���� : " << br.ratio << endl;
	os << "���� : " << br.tax_ratio << endl;
	return os;
}
void Save::set_ratio(double r)
{
	ratio = r;
}