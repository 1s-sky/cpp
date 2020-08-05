#include <iostream>
#include "Robot.h"
#pragma warning (disable : 4996)
using namespace std;

Robot::Robot() 
{
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");  // NULL string���� �ʱ�ȭ
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
	//this->energy = r.getenergy(); �̰͵� �����ϴ�
}
Robot::~Robot() 
{
	delete[] this->name;
}
void Robot::errPrn() 
{
	cout << "������ ����!" << endl;
}
void Robot::go()               // ���� �޽��� ��� �� ������ 10 ����
{
	if (this->energy >= 10) {
		cout << this->name << " ����" << endl;
		this->energy -= 10;
	}
	else {
		errPrn();
	}
}
void Robot::back()             // ���� �޽��� ��� �� ������ 20 ����
{
	if (this->energy >= 20) {
		cout << this->name << " ����" << endl;
		this->energy -= 20;
	}
	else {
		errPrn();
	}
}
void Robot::turn()             // �� �޽��� ��� �� ������ 30 ����
{
	if (this->energy >= 30) {
		cout << this->name << " ��" << endl;
		this->energy -= 30;
	}
	else {
		errPrn();
	}
}
void Robot::jump()            // ���� �޽��� ��� �� ������ 40 ����
{
	if (this->energy >= 40) {
		cout << this->name << " ����" << endl;
		this->energy -= 40;
	}
	else {
		errPrn();
	}
}
void Robot::charge(int e)      // e�� ��ŭ ����(������ ��� ������ ����)
{
	if (e >= 0) {
		this->energy += e;
	}
}
char* Robot::getName()         // name����� �� ����
{
	return this->name;
}
void Robot::setName(const char* name)   // name����� ���� ���޵� ���ڿ��� �� �ʱ�ȭ (��������)
{
	if (name != NULL) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}
int Robot::getEnergy()         // energy����� �� ����  
{
	return this->energy;
}
void Robot::setEnergy(int energy) {
	if (energy >= 0) {
		this->energy = energy;
	}
}