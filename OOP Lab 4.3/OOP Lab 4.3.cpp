#include <iostream>
#include "Bit String.h"
#include "Array.h"
#include "Decimal.h"
#include <sstream>
using namespace std;

int main() {

    Array* bs1 = new BitString();
    Array* bs2 = new BitString();
    Array* dec1 = new Decimal("54321");
    Array* dec2 = new Decimal("12345");

    static_cast<BitString*>(bs1)->setSize(8);
    static_cast<BitString*>(bs1)->setBit(0, true);
    static_cast<BitString*>(bs1)->setBit(2, true);
    static_cast<BitString*>(bs1)->setBit(4, true);
    static_cast<BitString*>(bs1)->setBit(6, true);

    static_cast<BitString*>(bs2)->setSize(8);
    static_cast<BitString*>(bs2)->setBit(0, true);
    static_cast<BitString*>(bs2)->setBit(1, true);
    static_cast<BitString*>(bs2)->setBit(4, true);
    static_cast<BitString*>(bs2)->setBit(5, true);

    BitString result_and = *dynamic_cast<BitString*>(bs1) & *dynamic_cast<BitString*>(bs2);
    BitString result_or = *dynamic_cast<BitString*>(bs1) | *dynamic_cast<BitString*>(bs2);
    BitString result_xor = *dynamic_cast<BitString*>(bs1) ^ *dynamic_cast<BitString*>(bs2);
    BitString result_not1 = ~*dynamic_cast<BitString*>(bs1);
    BitString result_not2 = ~*dynamic_cast<BitString*>(bs2);
    BitString result_shift_left = *dynamic_cast<BitString*>(bs1) << 2;
    BitString result_shift_right = *dynamic_cast<BitString*>(bs1) >> 3;
    
    std::cout << "bs1: ";
    bs1->display();
    std::cout << "bs2: ";
    bs2->display();
    std::cout << "bs1 & bs2: ";
    result_and.display();
    std::cout << "bs1 | bs2: ";
    result_or.display();
    std::cout << "bs1 ^ bs2: ";
    result_xor.display();
    std::cout << "~bs1: ";
    result_not1.display();
    std::cout << "~bs2: ";
    result_not2.display();
    std::cout << "bs1 << 2: ";
    result_shift_left.display();
    std::cout << "bs2 >> 3: ";
    result_shift_right.display();

    cout << "Type of bs1: " << typeid(*bs1).name() << endl;
    cout << "Type of bs2: " << typeid(*bs2).name() << endl;
    cout << "Type of Decimal object 1: " << typeid(*dec1).name() << endl;
    cout << "Type of Decimal object 2: " << typeid(*dec2).name() << endl;


    cout << "dec + " <<  * dynamic_cast<Decimal*>(dec1) + *dynamic_cast<Decimal*>(dec2) << endl;
    cout << "dec * " << (*dynamic_cast<Decimal*>(dec1)) * (*dynamic_cast<Decimal*>(dec2)) << endl;
    cout << "dec / " << (*dynamic_cast<Decimal*>(dec1)) / (*dynamic_cast<Decimal*>(dec2)) << endl;
    delete bs1;
    delete bs2;
    delete dec1;
    delete dec2;

    return 0;
}