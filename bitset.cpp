#include "bitset.h"

template <std::size_t N>
Bitset<N>::Bitset() {
    int length = N / BYTE + (N % BYTE != 0);
    unsigned char* bitset = new unsigned char[length]();
    this -> bitset = bitset; 
}

template <std::size_t N>
void Bitset<N>::set(std::size_t index)  {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    int pos = index % BYTE;
    int mask = 1 << pos;
    bitset[bitset_index] |= mask;
}

template <std::size_t N>
void Bitset<N>::reset(std::size_t index) {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    int pos = index % BYTE;
    int mask = 1 << pos;
    bitset[bitset_index] &= ~mask;
}

template <std::size_t N>
void Bitset<N>::flip(std::size_t index) {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    int pos = index % BYTE;
    int mask = 1 << pos;
    bitset[bitset_index] ^= mask;
}

template <std::size_t N>
int Bitset<N>::count() const {
    int count {};
    for (int i = 0; i < N; ++i) {
        if (test(i)) {
            ++count;
        }
    }
    return count;
}

template <std::size_t N>
bool Bitset<N>::any() const {
    for (int i = 0; i < N; ++i) {
        if (test(i)) {
            return true;
        }
    }
    return false;
}

template <std::size_t N>
bool Bitset<N>::all() const {
    for (int i = 0; i < N; ++i) {
        if (!test(i)) {
            return false;
        }
    }
    return true;
}

template <std::size_t N>
bool Bitset<N>::none() const {
    for (int i = 0; i < N; ++i) {
        if (test(i)) {
            return false;
        }
    }
    return true;
}

template <std::size_t N>
bool Bitset<N>::test(std::size_t i) const {
    check_out_of_range(i);
    int bitset_index = i / BYTE;
    int pos = i % BYTE;
    int bit_status = (bitset[bitset_index] >> pos) & 1;  	
    return bit_status;
}

template <std::size_t N>
void Bitset<N>::check_out_of_range(std::size_t pos) const {
    if (pos < 0 || pos >= N) {
        throw std::out_of_range("Index is out of range");
    }
}

template <std::size_t N>
int Bitset<N>::size() const {
    return N;
}

template <std::size_t M>
std::ostream& operator<<(std::ostream& os, const Bitset<M>& set) {  
    for (int i = M - 1; i >= 0; --i) {
        os << set.test(i);
    }   
    return os;
}

template <std::size_t N>
Bitset<N>::~Bitset() {
    delete[] bitset;
}
