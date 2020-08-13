#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char* str;
	int len;
public:
	MyString();
	MyString(const char* cp);
	MyString(const MyString &br);
	~MyString();
	MyString& operator=(const MyString& br);
	MyString operator+(const MyString& br);
	bool operator>(const MyString& br);
	friend ostream& operator<<(ostream& os, MyString& br);
	friend istream& operator>>(istream& os, MyString& br);
};