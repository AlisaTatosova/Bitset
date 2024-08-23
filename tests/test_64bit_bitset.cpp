#include <gtest/gtest.h>
#include "bitset_test.h"

TEST(Constructors64Bit, StringConstructor) {
    std::string bits = "10101011111111111111111111111111111111010101000101001010101011";
    Bitset<64> bitset(bits);
    std::bitset<64> std_bitset(bits);
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "String Constructor failed";
}

TEST(Constructors64Bit, IntConstructor) {
    unsigned long long num = 11123456;
    Bitset<64> int_ctor_bitset(num); 
    std::bitset<64> std_int_ctor_bitset(num);
    EXPECT_EQ(int_ctor_bitset.to_string(), std_int_ctor_bitset.to_string()) << "Integer Constructor failed";
}

TEST(Constructors64Bit, CopyConstructor) {
    std::string bits = "111110111111000101011001010010001111111111111111";
    Bitset<64> original(bits);
    Bitset<64> copy(original);
    EXPECT_EQ(original.to_string(), copy.to_string()) << "Copy Constructor failed";
}

TEST(Constructors64Bit, MoveConstructor) {
    std::string bits = "1111111110010011001100000000111001110110101001010100";
    Bitset<64> original(bits);
    Bitset<64> copy = original;
    Bitset<64> move_ctor_bitset(std::move(original));
    EXPECT_EQ(move_ctor_bitset.to_string(), copy.to_string()) << "Move Constructor failed";
}

TEST_F(Bitset64Bit, CopyAssignment) {
    std::vector<std::size_t> bits_to_set{10, 13, 34, 35, 37, 45, 53, 55, 62};
    set_bits(bits_to_set);
    test_copy_assignment();
}

TEST_F(Bitset64Bit, MoveAssignment) {
    std::vector<std::size_t> bits_to_set{55, 56, 57, 58, 59, 60, 61};
    set_bits(bits_to_set);
    test_move_assignment();  
}

TEST_F(Bitset64Bit, Set) {
    std::vector<std::size_t> bits_to_set{11, 16, 28, 30, 31, 42};
    set_bits(bits_to_set);
    test_set();
}

TEST_F(Bitset64Bit, Reset) {
    std::vector<std::size_t> bits_to_set{0, 1, 2, 3,  5, 6, 20, 21, 22, 45, 56, 61, 63};
    set_bits(bits_to_set);
    std::vector<std::size_t> bits_to_reset{5, 6, 20, 22};
    reset_bits(bits_to_reset);
    test_reset();
}

TEST_F(Bitset64Bit, Flip) {
    std::vector<std::size_t> bits_to_flip{20, 22, 26, 28, 30, 37, 44, 56, 62};
    flip_bits(bits_to_flip);
    test_flip();
}

TEST_F(Bitset64Bit, CountAnyNoneAll) {
    std::vector<std::size_t> bits_to_set{1, 2 , 13 , 14, 16, 18, 34, 63};
    set_bits(bits_to_set);
    test_count_any_none_all();
}

TEST_F(Bitset64Bit, BitwiseAnd) {
    std::vector<std::size_t> bits_to_set{33, 34, 35, 38, 39, 40};
    set_bits(bits_to_set);
    test_bitwise_and();
}

TEST_F(Bitset64Bit, BitwiseOR) {
    std::vector<std::size_t> bits_to_set{13, 14, 15, 16, 20, 36, 37, 38, 44, 56, 57, 60};
    set_bits(bits_to_set);
    test_bitwise_or();
}

TEST_F(Bitset64Bit, BitwiseXOR) {
    std::vector<std::size_t> bits_to_set{0, 15, 16, 27, 31, 42};
    set_bits(bits_to_set);
    test_bitwise_xor();
}

TEST_F(Bitset64Bit, BitwiseNOT) {
    std::vector<std::size_t> bits_to_set{1, 12, 23, 34, 45, 56};
    set_bits(bits_to_set);
    test_bitwise_not();
}

TEST_F(Bitset64Bit, ShiftLeft) {
    std::string bits = "10101011011110010010101010100010001010010110";
    bitset = Bitset<64>(bits);
    std_bitset = std::bitset<64>(bits);
    test_shift_left(16);
    test_shift_left_assign(35);
}

TEST_F(Bitset64Bit, ShifRight) {
    std::string bits = "11111001010001010111101010100101100010101010100111"; 
    bitset = Bitset<64>(bits);
    std_bitset = std::bitset<64>(bits);;
    test_shift_right(45);
    test_shift_right_assign(7);
}

TEST_F(Bitset64Bit, SubscriptOperators) {
    test_non_const_subscript(20, true);  
    test_non_const_subscript(25, false);
    test_non_const_subscript(62, false);

    std::string bits = "10010100100101010111001010010101001011010100100010";
    const Bitset<64> const_bitset(bits);
    test_const_subscript(const_bitset, 0, false);
    test_const_subscript(const_bitset, 1, true);
    test_const_subscript(const_bitset, 2, false);
}

TEST_F(Bitset64Bit, Equality) {
    std::string bits = "1010100101011011011111110100000101001010011010010011";
    Bitset<64> other1(bits);
    Bitset<64> other2(bits);
    EXPECT_FALSE(bitset == other1);
    EXPECT_TRUE(other1 == other2);
}

TEST_F(Bitset64Bit, Inequality) {
    std::string bits = "1011101010101000101010110101010100100111";
    Bitset<64> other1(bits);
    Bitset<64> other2(bits);
    EXPECT_TRUE(bitset != other1);
    EXPECT_FALSE(other1 != other2);
}

TEST_F(Bitset64Bit, ToString) {
    std::string bits = "1010110101010011100101010110101010011001";
    bitset = Bitset<64>(bits);
    std_bitset = std::bitset<64>(bits);;
    test_to_string();
}

TEST_F(Bitset64Bit, OutputStream) {
    std::string bits = "111010101011010110001000000010100100011000101010101";
    Bitset<64> other_bitset(bits);
    std::bitset<64> other_std(bits);
    bitset = other_bitset;
    std_bitset = other_std;
    test_output_stream();
}
