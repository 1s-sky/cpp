#include <iostream>
#include "Robot.h"
#pragma warning (disable : 4996)
using namespace std;

int main() {
	Robot ob1;
	Robot ob2("�±�V", 2000);
	Robot ob3(ob2);

	ob3.setName("����κ�");
	ob3.setEnergy(500);
	ob1.setName("���");
	ob1.setEnergy(200);

	ob1.go();
	ob2.back();
	ob3.turn();
	ob1.jump();
	
	ob2.charge(20);
	ob2.getEnergy();
	ob3.getName();
	ob1.setEnergy(10);
	ob1.jump();         //err�޼��� ���

	return 0;
}