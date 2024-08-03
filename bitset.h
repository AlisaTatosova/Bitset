#ifndef BITSET_H
#define BITSET_H
#include <iostream>
#include <cstddef>

template <std::size_t N>
class Bitset {
public:
    explicit Bitset();
    void set(std::size_t index) ;
    void reset(std::size_t index);
    void flip(std::size_t index);
    int count() const;
    bool any() const;
    bool none() const;
    bool all() const;
    bool test(std::size_t index) const;
    void check_out_of_range(std::size_t pos) const;
    int size() const;

    template <std::size_t M>
    friend std::ostream& operator<<(std::ostream& os, const Bitset<M>& set);

    ~Bitset();

private:
    unsigned char* bitset;
    static const int BYTE = 8;
};

#include "bitset.cpp"
#endif

