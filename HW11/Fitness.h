#pragma once
#include <iostream>
using namespace std;

class Fitness 
{
private:
	int num;
	char* name;
	double weight;
	double height;
public:
	//������, �Ҹ��� �Լ�
	Fitness();
	Fitness(int, char*, double, double);
	Fitness(const Fitness&);
	~Fitness();
	//������ �����ε�
	Fitness& operator=(Fitness&);
	bool operator==(Fitness&);
	//setter, getter �Լ�
	void setNum(int);
	int getNum();
	void setName(char*);
	char* getName();
	void setWeight(double);
	double getWeight();
	void setHeight(double);
	double getHeight();
	//��Ÿ
	double bmi();
};