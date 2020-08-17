#include <iostream>
#include "SmartArray.h"
using namespace std;

MyArray::MyArray(int s)
{
	this->ary = new int[s];
	this->size = s;
}
MyArray::MyArray(const MyArray& br)
{
	this->ary = new int[br.size];
	this->size = br.size;
}
MyArray& MyArray::operator=(const MyArray& br)
{
	if (this == &br) return *this;
	delete[] this->ary;
	this->ary = new int[br.size];
	for (int i = 0; i < br.size; i++) {
		this->ary[i] = br.ary[i];
	}
	this->size = br.size;
}
bool MyArray::put(int index, int val)
{
	if (index > this->size - 1) { return false; }
	else {
		if (val >= 0) {
			this->ary[index] = val;
			return true;
		}
		else return false;
	}
}
bool MyArray::get(int index, int& getdata)
{
	if (index > this->size - 1) { return false; }
	else {
		getdata =  this->ary[index];
		return true;
	}
}
int MyArray::getSize()
{
	return this->size;
}
int* MyArray::getAry()
{
	return this->ary;
}

bool SmartArray::put(int index, int val)
{
	if (index > this->getSize() - 1) { return false; }
	else {
		if (val >= 0) {
			if (val > this->max) { this->max = val; }
			this->getAry()[index] = val;
			return true;
		}
		else return false;
	}
}
int SmartArray::getMax()
{
	return this->max;
}
bool SmartArray::operator>(const SmartArray& br)
{
	if (this->max > br.max) return true;
	else return false;
}