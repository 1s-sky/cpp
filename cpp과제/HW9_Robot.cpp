#include <iostream>
#include "Robot.h"
#pragma warning (disable : 4996)
using namespace std;

Robot::Robot() 
{
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");  // NULL string으로 초기화
	this->energy = 0;
}
Robot::Robot(const char* name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}
Robot::Robot(const Robot& r) 
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
	//this->energy = r.getenergy(); 이것도 가능하다
}
Robot::~Robot() 
{
	delete[] this->name;
}
void Robot::errPrn() 
{
	cout << "에너지 부족!" << endl;
}
void Robot::go()               // 전진 메시지 출력 후 에너지 10 감소
{
	if (this->energy >= 10) {
		cout << this->name << " 전진" << endl;
		this->energy -= 10;
	}
	else {
		errPrn();
	}
}
void Robot::back()             // 후진 메시지 출력 후 에너지 20 감소
{
	if (this->energy >= 20) {
		cout << this->name << " 후진" << endl;
		this->energy -= 20;
	}
	else {
		errPrn();
	}
}
void Robot::turn()             // 턴 메시지 출력 후 에너지 30 감소
{
	if (this->energy >= 30) {
		cout << this->name << " 턴" << endl;
		this->energy -= 30;
	}
	else {
		errPrn();
	}
}
void Robot::jump()            // 점프 메시지 출력 후 에너지 40 감소
{
	if (this->energy >= 40) {
		cout << this->name << " 점프" << endl;
		this->energy -= 40;
	}
	else {
		errPrn();
	}
}
void Robot::charge(int e)      // e값 만큼 충전(음수일 경우 에너지 유지)
{
	if (e >= 0) {
		this->energy += e;
	}
}
char* Robot::getName()         // name멤버의 값 리턴
{
	return this->name;
}
void Robot::setName(const char* name)   // name멤버의 값을 전달된 문자열로 재 초기화 (깊은복사)
{
	if (name != NULL) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}
int Robot::getEnergy()         // energy멤버의 값 리턴  
{
	return this->energy;
}
void Robot::setEnergy(int energy) {
	if (energy >= 0) {
		this->energy = energy;
	}
}