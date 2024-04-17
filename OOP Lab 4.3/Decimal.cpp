#include <iostream>
#include <sstream>
#include "Decimal.h"
#include <string>
using namespace std;

int Decimal::getSize() const {
    return size;
}

void Decimal::setSize(int newSize) {
    size = newSize;
}


Decimal operator+(const Decimal& a, const Decimal& b) {
    Decimal result;
    int carry = 0;
    for (int i = 0; i < std::max(a.size, b.size) || carry; ++i) {
        int sum = carry;
        if (i < a.size) sum += a.bits[i];
        if (i < b.size) sum += b.bits[i];
        result.bits[i] = sum % 10;
        carry = sum / 10;
    }
    result.size = std::max(a.size, b.size);
    if (carry) {
        result.bits[result.size++] = carry;
    }
    return result;
}

Decimal operator-(const Decimal& a, const Decimal& b) {
    Decimal result;
    int borrow = 0;
    for (int i = 0; i < a.size; ++i) {
        int diff = a.bits[i] - borrow;
        if (i < b.size) diff -= b.bits[i];
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result.bits[i] = diff;
    }
    while (result.size > 1 && result.bits[result.size - 1] == 0) {
        --result.size;
    }
    return result;
}

Decimal operator*(const Decimal& a, const Decimal& b) {
    Decimal result;
    for (int i = 0; i < a.size; ++i) {
        int carry = 0;
        for (int j = 0; j < b.size || carry; ++j) {
            int mul = result.bits[i + j] + a.bits[i] * (j < b.size ? b.bits[j] : 0) + carry;
            result.bits[i + j] = mul % 10;
            carry = mul / 10;
        }
    }
    result.size = a.size + b.size;
    while (result.size > 1 && result.bits[result.size - 1] == 0) {
        --result.size;
    }
    return result;
}

Decimal operator/(const Decimal& a, const Decimal& b) {
    if (b.size == 1 && b.bits[0] == 0) {
        throw std::runtime_error("Division by zero");
    }

    Decimal quotient;
    Decimal remainder = a;
    for (int i = a.size - 1; i >= 0; --i) {
        remainder = remainder * 10 + Decimal();
        int count = 0;
        while (remainder >= b) {
            remainder = remainder - b;
            ++count;
        }
        quotient.bits[i] = count;
    }

    quotient.size = a.size;
    while (quotient.size > 1 && quotient.bits[quotient.size - 1] == 0) {
        --quotient.size;
    }
    return quotient;
}

Decimal operator%(const Decimal& a, const Decimal& b) {
    if (b.size == 1 && b.bits[0] == 0) {
        throw std::runtime_error("Division by zero");
    }

    Decimal remainder = a;
    for (int i = a.size - 1; i >= 0; --i) {
        remainder = remainder * 10 + Decimal(std::to_string(a.bits[i]));
        int count = 0;
        while (remainder >= b) {
            remainder = remainder - b;
            ++count;
        }
    }
    return remainder;
}


bool operator==(const Decimal& a, const Decimal& b) {
    if (a.size != b.size) return false;
    for (int i = 0; i < a.size; ++i) {
        if (a.bits[i] != b.bits[i]) return false;
    }
    return true;
}

bool operator!=(const Decimal& a, const Decimal& b) {
    return !(a == b);
}

bool operator<(const Decimal& a, const Decimal& b) {
    if (a.size != b.size) return a.size < b.size;
    for (int i = a.size - 1; i >= 0; --i) {
        if (a.bits[i] != b.bits[i]) return a.bits[i] < b.bits[i];
    }
    return false;
}

bool operator>(const Decimal& a, const Decimal& b) {
    return b < a;
}

bool operator<=(const Decimal& a, const Decimal& b) {
    return !(b < a);
}

bool operator>=(const Decimal& a, const Decimal& b) {
    return !(a < b);
}

std::ostream& operator << (ostream& out, const Decimal& r)
{
    out << string(r);
    return out;
}

Decimal::operator std::string() const {
    std::stringstream ss;
    for (int i = size - 1; i >= 0; --i) {
        ss << static_cast<int>(bits[i]);
    }
    return ss.str();
}

bool Decimal::operator [](int index) const {
    return bits[index] > 0;
}

Decimal& Decimal::operator=(const Array& other) {
    if (this != &other) {
        size = other.getSize();
        const Decimal& temp = dynamic_cast<const Decimal&>(other);
        for (int i = 0; i < size; ++i) {
            bits[i] = temp.bits[i];
        }
    }
    return *this;
}

void Decimal::display() const{
    for (int i = 0; i < size; i++) {
        cout << bits[i];
    }
}