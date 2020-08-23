#pragma once
#include <iostream>
template <typename T>
class MyArray
{
private:
	T* ary;
	T size;
public:
	MyArray() { ary = NULL; size = 0; }
	MyArray(T s);
	MyArray(const MyArray<T>& br);
	~MyArray() { delete[] ary; }
	MyArray& operator=(const MyArray<T>& br);
	bool put(int index, T val);
	bool get(int index, T& getdata);
	int getSize();
	int* getAry();
};

template <typename T>
MyArray<T>::MyArray(T s)
{
	this->ary = new T[s];
	this->size = s;
}
template <typename T>
MyArray<T>::MyArray(const MyArray<T>& br)
{
	this->ary = new T[br.size];
	this->size = br.size;
}
template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& br)
{
	if (this == &br) return *this;
	delete[] this->ary;
	this->ary = new T[br.size];
	for (int i = 0; i < br.size; i++) {
		this->ary[i] = br.ary[i];
	}
	this->size = br.size;
}
template <typename T>
bool MyArray<T>::put(int index, T val)
{
	if (index > this->size - 1 || index < 0) { return false; }
	else {
		this->ary[index] = val;
		return true;
	}
}
template <typename T>
bool MyArray<T>::get(int index, T& getdata)
{
	if (index > this->size - 1 || index < 0) { return false; }
	else {
		getdata = this->ary[index];
		return true;
	}
}
template <typename T>
int MyArray<T>::getSize()
{
	return this->size;
}
template <typename T>
int* MyArray<T>::getAry()
{
	return this->ary;
}