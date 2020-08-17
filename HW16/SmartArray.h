#pragma once
#include <iostream>
class MyArray
{
private:
	int* ary;
	int size;
public:
	MyArray() { ary = NULL; size = 0; }
	MyArray(int s);
	MyArray(const MyArray& br);
	~MyArray() { delete[] ary; }
	MyArray& operator=(const MyArray& br);
	bool put(int index, int val);
	bool get(int index, int& getdata);
	int getSize();
	int* getAry();
};

class SmartArray : public MyArray
{
private:
	int max;
public:
	SmartArray() : max(0) {}
	SmartArray(int s) : MyArray(s), max(0) {}
	bool put(int index, int val);
	int getMax();
	bool operator>(const SmartArray& br);
};