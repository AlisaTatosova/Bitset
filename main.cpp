#include <iostream>
#include "bitset.h"

int main() {
    Bitset<8> bitset("10101110");
    bitset.set(0);
    bitset.flip(1);
    bitset.reset(7);
    std::cout << bitset << std::endl;
}
