#include <iostream>
#include "Fitness.h"
#pragma warning (disable : 4996)
using namespace std;

Fitness::Fitness() 
{
	this->num = 0;
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");
	this->weight = 0;
	this->height = 0;
}
Fitness::Fitness(int num, char* name, double weight, double height) 
{
	this->num = num;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->weight = weight;
	this->height = height;
}
Fitness::Fitness(const Fitness& r) 
{
	this->num = r.num;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->weight = weight;
	this->height = height;
}
Fitness::~Fitness() 
{
	delete[] name;
}
//연산자 오버로딩
Fitness& Fitness::operator=(Fitness& r)
{
	if (this == &r) { return *this; }
	delete[] this->name;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->num = r.num;
	this->height = r.height;
	this->weight = r.weight;
	return *this;
}
bool Fitness::operator==(Fitness &r)
{
	if (this->name == r.name) return true;
	else return false;
}
//setter, getter 함수
void Fitness::setNum(int num)
{
	this->num = num;
}
int Fitness::getNum()
{
	return this->num;
}
void Fitness::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char* Fitness::getName()
{
	return this->name;
}
void Fitness::setWeight(double weight)
{
	this->weight = weight;
}
double Fitness::getWeight()
{
	return this->weight;
}
void Fitness::setHeight(double height)
{
	this->height = height;
}
double Fitness::getHeight()
{
	return this->height;
}
//기타
double Fitness::bmi()
{
	double bmi;
	bmi = weight / (height / 100 * height / 100);
	return bmi;
}