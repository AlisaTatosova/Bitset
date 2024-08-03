#include "bit_manipulator.h"
#include "bitset.h"

template <std::size_t N>
BitManipulator<N>::BitManipulator(Bitset<N>& bitset, std::size_t pos) 
    : bitset{bitset}, pos{pos} {}

template <std::size_t N>
BitManipulator<N>& BitManipulator<N>::operator=(bool value) {
    bitset.set(pos, value);
    return *this;
}

// to be able to cout the non-const bitset's i-th bit, std::cout << bitset1[3]; bitset1 is non-const object 
template <std::size_t M>
std::ostream& operator<<(std::ostream& os, const BitManipulator<M>& byte) { 
    os << byte.bitset.test(byte.pos);
    return os;
}
