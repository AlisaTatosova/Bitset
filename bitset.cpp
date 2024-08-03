#include "bitset.h"

template <std::size_t N>
void Bitset<N>::initialize() {
    int length = N / BYTE + (N % BYTE != 0);
    unsigned char* bitset = new unsigned char[length]();
    this -> bitset = bitset; 
    this -> length = length;
}

template <std::size_t N>
Bitset<N>::Bitset() {
    initialize();
}

template <std::size_t N>
Bitset<N>::Bitset(const std::string& bits) {
    initialize();
    int start = 0;
    if (bits.size() > N) {
        start = bits.size() - N;
    }
    for (int i = 0; i < bits.size() && i < N; ++i) {
        if (bits[bits.size() - 1 - i - start] == '1') {
            set(i);
        } else if (bits[bits.size() - 1 - i - start] != '0') {
            throw std::invalid_argument("Invalid character in string. Only '0' and '1' are allowed to be given in string as bit.");
        } 
    }
}
template <std::size_t N>
Bitset<N>::Bitset(unsigned int number) {
    initialize(); 
    for (int i = 0; i < N; ++i) {
        if (number == 0) {
            break;
        }

        if (number & 1) { 
            set(i);
        }
        number >>= 1;
    }
}

template <std::size_t N>
Bitset<N>::Bitset(const Bitset& other) : length{other.length} {
    bitset = new unsigned char[other.length]();
    for (int i = 0; i < other.length; ++i) {
        bitset[i] = other.bitset[i];
    }
}

template <std::size_t N>
Bitset<N>::Bitset(Bitset&& other) noexcept
    : length{other.length}, bitset{other.bitset} {
    other.bitset = nullptr;
    other.length = 0;
}

template <std::size_t N>
Bitset<N>& Bitset<N>::operator=(const Bitset<N>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] bitset;
    length = other.length;
    bitset = new unsigned char[length]();
    for (int i = 0; i < length; ++i) {
        bitset[i] = other.bitset[i];
    }
    return *this;
}

template <std::size_t N>
Bitset<N>& Bitset<N>::operator=(Bitset<N>&& other) noexcept {
    if (this != &other) {
        delete[] bitset;
        bitset = other.bitset;
        length = other.length;
        other.bitset = nullptr;
        other.length = 0;
    }
    return *this;
}

template <std::size_t N>
std::size_t Bitset<N>::get_mask(std::size_t index) const {
    int pos = index % BYTE;
    return 1 << pos;
}

template <std::size_t N>
void Bitset<N>::set(std::size_t index, bool bit_status)  {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    if (bit_status) {
        bitset[bitset_index] |= get_mask(index);
    } else {
        reset(index);
    }
}

template <std::size_t N>
void Bitset<N>::reset(std::size_t index) {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    bitset[bitset_index] &= ~get_mask(index);
}

template <std::size_t N>
void Bitset<N>::flip(std::size_t index) {
    check_out_of_range(index);
    int bitset_index = index / BYTE;
    bitset[bitset_index] ^= get_mask(index);
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
    return (bitset[bitset_index] >> pos) & 1;
}

template <std::size_t N>
BitManipulator<N> Bitset<N>::operator[](std::size_t index) {
    check_out_of_range(index);
    return BitManipulator<N>(*this, index);
}

template <std::size_t N>
bool Bitset<N>::operator[](std::size_t index) const {
    return test(index);
}

template <std::size_t N>
void Bitset<N>::check_out_of_range(std::size_t pos) const {
    if (pos >= N) {
        throw std::out_of_range("Index is out of range");
    }
}

template <std::size_t N>
unsigned long Bitset<N>::to_ulong() const{
    unsigned long result = 0;
    for (int i = 0; i < N; ++i) {
        if (i > sizeof(unsigned long) * 8 && test(i)) {
            throw std::overflow_error("Bitset size exceeds the maximum number of bits in an unsigned long.");
        }

        if (test(i)) {
            result |= (1 << i);
        }
    }
    return result;
}

template <std::size_t N>
std::string Bitset<N>::to_string() const {
    std::string str(N, '0');
    for (std::size_t i = 0; i < N; ++i) {
        if (test(i)) {
            str[N - 1 - i] = '1';
        }
    }
    return str;
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
