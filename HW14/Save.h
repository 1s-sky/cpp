#pragma once
#include <iostream>
using namespace std;

class Save
{
private:
	char name[20];
	int capital;
	int profit;
	int tax;
	int tot;
	static double ratio;
public:
	static double tax_ratio;
	Save(const char* np = "¾Æ¹«°³", int n = 0);
	void calculate();
	friend ostream& operator<<(ostream& os, const Save& br);
	static void set_ratio(double r);
};