#ifndef BITMANIPULATOR_H
#define BITMANIPULATOR_H

template <std::size_t N>
class Bitset;

// class for helping to operator[] non-const, to have write access 
template <std::size_t N>
class BitManipulator {
public:
    BitManipulator(Bitset<N>& bitset, std::size_t pos);
    BitManipulator& operator=(const BitManipulator& other);
    BitManipulator& operator=(bool value);
    operator bool();

    template <std::size_t M>
    friend std::ostream& operator<<(std::ostream& os, const BitManipulator<M>& byte);  // to be able to cout the non-const bitset's i-th bit, std::cout << bitset1[3]; bitset1 is non-const object 

private:
    Bitset<N>& bitset;
    std::size_t pos;
};

#include "bit_manipulator.cpp"
#endif