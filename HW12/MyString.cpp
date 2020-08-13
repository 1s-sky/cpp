#pragma warning (disable : 4996)
#include <iostream>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	this->str = new char[strlen("") + 1];
	this->len = 0;
}
MyString::MyString(const char* cp)
{
	this->str = new char[strlen(cp) + 1];
	strcpy(this->str, cp);
	this->len = strlen(cp);
}
MyString::MyString(const MyString& br)
{
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
}
MyString::~MyString()
{
	delete[] this->str;
}
MyString& MyString::operator=(const MyString& br)
{
	if (this == &br) { return *this; }
	delete[] this->str;
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
}
MyString MyString::operator+(const MyString& br)
{
	MyString res;
	int i = 0;
	int k = 0;

	res.len = this->len + br.len;
	res.str = new char[res.len + 1];
	for (i = 0; i < this->len; i++)
	{
		res.str[i] = this->str[i];
	}
	for (int j = i; j < res.len + 1; j++, k++)
	{
		res.str[j] = br.str[k];
	}
	return res;
}
bool MyString::operator>(const MyString& br)
{
	if (this->len > br.len) return true;
	else return false;
}