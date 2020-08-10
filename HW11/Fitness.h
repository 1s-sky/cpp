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
	//생성자, 소멸자 함수
	Fitness();
	Fitness(int, char*, double, double);
	Fitness(const Fitness&);
	~Fitness();
	//연산자 오버로딩
	Fitness& operator=(Fitness&);
	bool operator==(Fitness&);
	//setter, getter 함수
	void setNum(int);
	int getNum();
	void setName(char*);
	char* getName();
	void setWeight(double);
	double getWeight();
	void setHeight(double);
	double getHeight();
	//기타
	double bmi();
};