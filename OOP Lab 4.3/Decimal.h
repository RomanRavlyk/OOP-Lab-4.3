#pragma once
#include "Array.h"
#include <iostream>
#include <sstream>
#include <string>
class Decimal : public Array {
public: 
	Decimal() : Array(0) {
		for (int i = 0; i < size; i++) {
			bits[i] = 0;
		}
	}
	Decimal(int size) : Array(size) { std::fill_n(bits, MAX_SIZE, 0); }
	Decimal(const std::string& value) : Array(value.size()) {
		for (int i = 0; i < size; ++i) {
			if (value[i] < '0' || value[i] > '9') {
				throw std::invalid_argument("Invalid decimal string");
			}
			bits[i] = value[i] - '0';
		}
	}
	int getSize() const override;
	void setSize(int newSize) override;

	friend bool operator==(const Decimal& a, const Decimal& b);
	friend bool operator!=(const Decimal& a, const Decimal& b);
	friend bool operator<(const Decimal& a, const Decimal& b);
	friend bool operator>(const Decimal& a, const Decimal& b);
	friend bool operator<=(const Decimal& a, const Decimal& b);
	friend bool operator>=(const Decimal& a, const Decimal& b);

	friend std::ostream& operator << (std::ostream&, const Decimal&);

	virtual Decimal& operator=(const Array& other) override;
	virtual bool operator[](int index) const override;
	virtual operator std::string() const override;
	virtual void display() const override;
	friend Decimal operator+(const Decimal& a, const Decimal& b);
	friend Decimal operator-(const Decimal& a, const Decimal& b);
	friend Decimal operator*(const Decimal& a, const Decimal& b);
	friend Decimal operator/(const Decimal& a, const Decimal& b);
	friend Decimal operator%(const Decimal& a, const Decimal& b);
};