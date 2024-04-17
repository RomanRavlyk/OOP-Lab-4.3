#pragma once
#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

class BitString: public Array {
public:
	BitString() : Array(0) {}
	BitString(int size): Array(size) {}
	BitString(const BitString& other) {
		size = other.size;
		for (int i = 0; i < MAX_SIZE / 8 + 1; ++i)
			bits[i] = other.bits[i];
	}

	int getSize() const { return size; }
	void setSize(int newSize) { size = newSize; }
	void setBit(int index, bool value);
	bool getBit(int index) const;
	virtual void display() const override;
	friend BitString operator &(const BitString& other, const BitString& other2);
	friend BitString operator |(const BitString& other, const BitString& other2);
	friend BitString operator ^(const BitString& other, const BitString& other2);
	friend BitString operator ~(const BitString& other);
	friend BitString operator <<(const BitString& other, int shift);
	friend BitString operator >>(const BitString& other, int shift);

	virtual BitString& operator=(const Array& other) override;
	virtual bool operator[](int index) const override;
	virtual operator string() const override;
};