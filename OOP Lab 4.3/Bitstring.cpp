#include <iostream>
#include <string>
#include <sstream>
#include "Bit String.h"

using namespace std;

void BitString::setBit(int index, bool value) {
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    if (value)
        bits[byteIndex] |= (1 << bitIndex);
    else
        bits[byteIndex] &= ~(1 << bitIndex);
}

bool BitString::getBit(int index) const {
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    return (bits[byteIndex] >> bitIndex) & 1;
}

BitString operator&(const BitString& other1, const BitString& other2) {
    BitString result;
    int resultSize = (other1.size < other2.size) ? other1.size : other2.size;
    result.setSize(resultSize);
    for (int i = 0; i < resultSize; ++i)
        result.setBit(i, other1.getBit(i) && other2.getBit(i));
    return result;
}

BitString operator|(const BitString& other, const BitString& other2) {
    BitString result;
    int resultSize = (other.size > other2.size) ? other.size : other2.size;
    result.setSize(resultSize);
    for (int i = 0; i < resultSize; ++i)
        result.setBit(i, other.getBit(i) || other2.getBit(i));
    return result;
}
BitString operator^(const BitString& other, const BitString& other2) {
    BitString result;
    int resultSize = (other.size > other2.size) ? other.size : other2.size;
    result.setSize(resultSize);
    for (int i = 0; i < resultSize; ++i)
        result.setBit(i, other.getBit(i) ^ other2.getBit(i));
    return result;
}

BitString operator~(const BitString& other) {
    BitString result;
    result.setSize(other.size);
    for (int i = 0; i < other.size; ++i)
        result.setBit(i, !other.getBit(i));
    return result;
}

BitString operator<<(const BitString& other, int shift) {
    BitString result;
    result.setSize(other.size);
    for (int i = 0; i < other.size - shift; ++i)
        result.setBit(i + shift, other.getBit(i));
    return result;
}

BitString operator>>(const BitString& other, int shift) {
    BitString result;
    result.setSize(other.size);
    for (int i = shift; i < other.size; ++i)
        result.setBit(i - shift, other.getBit(i));
    return result;
}

BitString& BitString::operator=(const Array& other) {
    if (this != &other) {
        const BitString& bs = dynamic_cast<const BitString&>(other);
        size = bs.size;
        for (int i = 0; i < MAX_SIZE / 8 + 1; ++i)
            bits[i] = bs.bits[i];
    }
    return *this;
}


bool BitString::operator[](int index) const {
    int byteIndex = index / 8;
    int bitIndex = index % 8;
    return (bits[byteIndex] >> bitIndex) & 1;
}

void BitString::display() const {
    for (int i = 0; i < size; i++) {
        std::cout << getBit(i);
    }
    std::cout << std::endl;
}

BitString::operator string() const {
    stringstream ss;
    ss << "Your array: ";
    for (int i = 0; i < size; i++) {
        ss << static_cast<int>(bits[i]) << " ";
    }
    ss << endl;
    return ss.str();
};