#pragma once
#include "MyArray.h"

template <typename T>
class SmartArray : public MyArray<T>
{
private:
	T max;
public:
	SmartArray() {}
	SmartArray(int s) : MyArray<T>(s), max(0) {}
	bool put(int index, T val) {
		if (index > this->getSize() - 1 || index < 0) { return false; }
		else {
			if (val >= 0) {
				if (val > this->max) { this->max = val; }
				this->getAry()[index] = val;
				return true;
			}
			else return false;
		}
	}
	T getMax() { return this->max; }
	bool operator>(const SmartArray<T>& br) {
		if (this->max > br.max) return true;
		else return false;
	}
};