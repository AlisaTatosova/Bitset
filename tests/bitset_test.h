#ifndef BITSET_TEST_H
#define BITSET_TEST_H

#include <gtest/gtest.h>
#include <bitset>
#include "../bitset.h" 

template <std::size_t N>
class BitsetTest : public ::testing::Test {
protected:
    void set_bits(const std::vector<std::size_t>& bits);
    void reset_bits(const std::vector<std::size_t>& bits);
    void flip_bits(const std::vector<std::size_t>& bits);
    
protected:
    void test_set();
    void test_reset();
    void test_flip();
    void test_count_any_none_all();
    void test_copy_assignment();
    void test_move_assignment();
    void test_bitwise_and();
    void test_bitwise_or();
    void test_bitwise_xor();
    void test_bitwise_not();
    void test_to_ulong(); 
    void test_to_string(); 
    void test_shift_left(std::size_t positions);
    void test_shift_right(std::size_t positions);
    void test_shift_left_assign(std::size_t positions);
    void test_shift_right_assign(std::size_t positions);
    void test_non_const_subscript(std::size_t index, bool value);
    void test_const_subscript(const Bitset<N>& set, std::size_t index, bool expected_value);
    void test_output_stream();

protected:
    Bitset<N> bitset;
    std::bitset<N> std_bitset;
};

template <std::size_t N>
void BitsetTest<N>::set_bits(const std::vector<std::size_t>& bits) {
    for (std::size_t bit : bits) {
        bitset.set(bit);
        std_bitset.set(bit);
    }
}

template <std::size_t N>
void BitsetTest<N>::reset_bits(const std::vector<std::size_t>& bits) {
    for (std::size_t bit : bits) {
        bitset.reset(bit);
        std_bitset.reset(bit);
    }
}

template <std::size_t N>
void BitsetTest<N>::flip_bits(const std::vector<std::size_t>& bits) {
    for (std::size_t bit : bits) {
        bitset.flip(bit);
        std_bitset.flip(bit);
    }
}

template <std::size_t N>
void BitsetTest<N>::test_set() {
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Set function failed";
}

template <std::size_t N>
void BitsetTest<N>::test_reset() {
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Reset function failed";
}

template <std::size_t N>
void BitsetTest<N>::test_flip() {
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Flip function failed";
}

template <std::size_t N>
void BitsetTest<N>::test_count_any_none_all() {
    EXPECT_EQ(bitset.count(), std_bitset.count()) << "Count function failed!";
    EXPECT_EQ(bitset.any(), std_bitset.any()) << "Any function failed!";
    EXPECT_EQ(bitset.none(), std_bitset.none()) << "None function failed!";
    EXPECT_EQ(bitset.all(), std_bitset.all()) << "All function failed!";
}

template <std::size_t N>
void BitsetTest<N>::test_copy_assignment() {
    Bitset<N> bitset_copy;
    bitset_copy = bitset;
    EXPECT_EQ(bitset.to_string(), bitset_copy.to_string()) << "Copy Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_move_assignment() {
    Bitset<N> bitset_move;
    Bitset<N> bitset_copy(bitset);
    bitset_move = std::move(bitset);

    EXPECT_EQ(bitset_move.to_string(), bitset_copy.to_string())  << "Move Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_bitwise_and() {
    std::string bits = "110010100101001010100101010111101010100101011111";
    Bitset<N> other(bits);
    std::bitset<N> std_other(bits);

    Bitset<N> and_result = bitset & other;
    std::bitset<N> std_and_result = std_bitset & std_other;
    EXPECT_EQ(and_result.to_string(), std_and_result.to_string()) << "Bitwise AND failed";

    bitset &= other;
    std_bitset &= std_other;
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Bitwise AND Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_bitwise_or() {
    std::string bits = "110010100101001010101101010111101010100101011";
    Bitset<N> other(bits);
    std::bitset<N> std_other(bits);

    Bitset<N> or_result = bitset | other;
    std::bitset<N> std_or_result = std_bitset | std_other;
    EXPECT_EQ(or_result.to_string(), std_or_result.to_string()) << "Bitwise OR failed";

    bitset |= other;
    std_bitset |= std_other;
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Bitwise OR Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_bitwise_xor() {
    std::string bits = "11111110001110011010101101010111101010100101011";
    Bitset<N> other(bits);
    std::bitset<N> std_other(bits);

    Bitset<N> xor_result = bitset ^ other;
    std::bitset<N> std_xor_result = std_bitset ^ std_other;
    EXPECT_EQ(xor_result.to_string(), std_xor_result.to_string()) << "Bitwise XOR failed";

    bitset ^= other;
    std_bitset ^= std_other;
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Bitwise XOR Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_bitwise_not() {
    Bitset<N> not_result = ~bitset;
    std::bitset<N> std_not_result = ~std_bitset;
    EXPECT_EQ(not_result.to_string(), std_not_result.to_string()) << "Bitwise NOT failed";
}

template <size_t N>
void BitsetTest<N>::test_to_ulong() {
    EXPECT_EQ(bitset.to_ulong(), std_bitset.to_ulong()) << "to_ulong function failed";
}

template <size_t N>
void BitsetTest<N>::test_to_string() {
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "to_string function failed";
}

template <std::size_t N>
void BitsetTest<N>::test_shift_left(std::size_t positions) {
    Bitset<N> result = bitset << positions;
    std::bitset<N> std_result = std_bitset << positions;
    EXPECT_EQ(result.to_string(), std_result.to_string()) << "Left Shift failed";
}

template <std::size_t N>
void BitsetTest<N>::test_shift_right(std::size_t positions) {
    Bitset<N> result = bitset >> positions;
    std::bitset<N> std_result = std_bitset >> positions;
    EXPECT_EQ(result.to_string(), std_result.to_string()) << "Right Shift failed";
}

template <std::size_t N>
void BitsetTest<N>::test_shift_left_assign(std::size_t positions) {
    bitset <<= positions;
    std_bitset <<= positions;
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Left Shift Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_shift_right_assign(std::size_t positions) {
    bitset >>= positions;
    std_bitset >>= positions;
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "Right Shift Assignment failed";
}

template <std::size_t N>
void BitsetTest<N>::test_non_const_subscript(std::size_t index, bool value) {
    bitset[index] = value;  
    EXPECT_EQ(bitset.test(index), value) << "Non-Const subscript operator failed";
}

template <std::size_t N>
void BitsetTest<N>::test_const_subscript(const Bitset<N>& set, size_t index, bool expected_value) {
    EXPECT_EQ(set[index], expected_value) << "Const subscript operator failed"; 
}

template <std::size_t N>
void BitsetTest<N>::test_output_stream() {
    std::stringstream ss_custom;
    std::stringstream ss_std;
    ss_custom << bitset;
    ss_std << std_bitset;
    EXPECT_EQ(ss_custom.str(), ss_std.str()) << "Output stream operator failed";
}

using Bitset7Bit = BitsetTest<7>;
using Bitset23Bit = BitsetTest<23>;
using Bitset64Bit = BitsetTest<64>;

#endif 
