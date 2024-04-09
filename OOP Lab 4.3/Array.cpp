#include "Array.h"
#include <iostream>
using namespace std;

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        this->size = other.size;
    }
    return *this;
}