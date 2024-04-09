#pragma once
#include <iostream>
#include <string>

class Array {
protected:
	static const int MAX_SIZE = 100;
	int size;
public:
	Array() : size(0) {};
	Array(int size) : size(size) {};
	virtual ~Array() {};

	virtual int getSize() const = 0;
	virtual void setSize(int newSize) = 0;
	virtual Array& operator=(const Array& other);
	virtual bool operator[](int index) const = 0;
	virtual operator std::string() const = 0;
	virtual void display() const = 0;
};