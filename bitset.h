#ifndef BITSET_H
#define BITSET_H
#include <iostream>
#include <cstddef>
#include "bit_manipulator.h"

template <std::size_t N>
class Bitset {
public:
    Bitset();
    explicit Bitset(const std::string& bits);
    explicit Bitset(unsigned int number);
    Bitset(const Bitset& other);
    Bitset& operator=(const Bitset& other);
    Bitset(Bitset&& other) noexcept;
    Bitset& operator=(Bitset&& other) noexcept;
    void initialize();
    void set(std::size_t index, bool value = true);
    void reset(std::size_t index);
    void flip(std::size_t index);
    int count() const;
    bool any() const;
    bool none() const;
    bool all() const;
    bool test(std::size_t index) const;
    int size() const;
    unsigned long to_ulong() const;
    std::string to_string() const;
    
    BitManipulator<N> operator[](std::size_t index);
    bool operator[](std::size_t index) const;

    template <std::size_t M> 
    friend std::ostream& operator<<(std::ostream& os, const Bitset<M>& set);

    ~Bitset();

private:
    void check_out_of_range(std::size_t pos) const;
    std::size_t get_mask(std::size_t index) const;

private:
    unsigned char* bitset;
    std::size_t length;
    static const int BYTE = 8;
};

#include "bitset.cpp"
#endif

