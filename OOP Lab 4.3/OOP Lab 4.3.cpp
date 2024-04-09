#include <iostream>
#include "Bit String.h"
#include "Decimal.h"
#include <sstream>
using namespace std;

int main() {

        BitString bs1, bs2;


        bs1.setSize(8);
        bs1.setBit(0, true);
        bs1.setBit(1, false);
        bs1.setBit(2, true);
        bs1.setBit(3, false);
        bs1.setBit(4, true);
        bs1.setBit(5, false);
        bs1.setBit(6, true);
        bs1.setBit(7, false);


        bs2.setSize(8);
        bs2.setBit(0, true);
        bs2.setBit(1, true);
        bs2.setBit(2, false);
        bs2.setBit(3, false);
        bs2.setBit(4, true);
        bs2.setBit(5, true);
        bs2.setBit(6, false);
        bs2.setBit(7, false);


        BitString result_and = bs1 & bs2;
        BitString result_or = bs1 | bs2;
        BitString result_xor = bs1 ^ bs2;
        BitString result_not1 = ~bs1;
        BitString result_not2 = ~bs2;
        BitString result_shift_left = bs1 << 2;
        BitString result_shift_right = bs2 >> 3;


        std::cout << "bs1: ";
        bs1.display();
        std::cout << "bs2: ";
        bs2.display();
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

        string bs_string = static_cast<string>(bs1);


        Decimal decimalObject("54321");
        Decimal anotherDecimalObject("12345");

  
        cout << "Decimal object 1: ";
        cout << decimalObject; cout << endl;

        cout << "Decimal object 2: ";
        cout << anotherDecimalObject; cout << endl;


        cout << "Real type of Decimal object 1: " << typeid(decimalObject).name() << endl;
        cout << "Real type of Decimal object 2: " << typeid(anotherDecimalObject).name() << endl;

        return 0;
}