#include <gtest/gtest.h>
#include "bitset_test.h"

TEST(Constructors23Bit, StringConstructor) {
    std::string bits = "10101010101010101010111";
    Bitset<23> bitset(bits);
    std::bitset<23> std_bitset(bits);
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "String Constructor failed";
}

TEST(Constructors23Bit, IntConstructor) {
    unsigned long long num = 134566;
    Bitset<23> int_ctor_bitset(num); 
    std::bitset<23> std_int_ctor_bitset(num);
    EXPECT_EQ(int_ctor_bitset.to_string(), std_int_ctor_bitset.to_string()) << "Integer Constructor failed";
}

TEST(Constructors23Bit, CopyConstructor) {
    std::string bits = "111110111111111111111111111";
    Bitset<23> original(bits);
    Bitset<23> copy(original);
    EXPECT_EQ(original.to_string(), copy.to_string()) << "Copy Constructor failed";
}

TEST(Constructors23Bit, MoveConstructor) {
    std::string bits = "1111111110000000011100100";
    Bitset<23> original(bits);
    Bitset<23> copy = original;
    Bitset<23> move_ctor_bitset(std::move(original));
    EXPECT_EQ(move_ctor_bitset.to_string(), copy.to_string()) << "Move Constructor failed";
}

TEST_F(Bitset23Bit, CopyAssignment) {
    std::vector<std::size_t> bits_to_set{10, 13, 21, 22};
    set_bits(bits_to_set);
    test_copy_assignment();
}

TEST_F(Bitset23Bit, MoveAssignment) {
    std::vector<std::size_t> bits_to_set{5, 11, 12, 13, 21};
    set_bits(bits_to_set);
    test_move_assignment();  
}

TEST_F(Bitset23Bit, Set) {
    std::vector<std::size_t> bits_to_set{1, 15, 18, 20, 21, 22};
    set_bits(bits_to_set);
    test_set();
}

TEST_F(Bitset23Bit, Reset) {
    std::vector<std::size_t> bits_to_set{0, 1, 2, 3,  5, 6, 20, 21, 22};
    set_bits(bits_to_set);
    std::vector<std::size_t> bits_to_reset{1, 2, 3};
    reset_bits(bits_to_reset);
    test_reset();
}

TEST_F(Bitset23Bit, Flip) {
    std::vector<std::size_t> bits_to_flip{10, 12, 16, 18, 20};
    flip_bits(bits_to_flip);
    test_flip();
}

TEST_F(Bitset23Bit, CountAnyNoneAll) {
    std::vector<std::size_t> bits_to_set{1, 2 , 13 , 14, 16};
    set_bits(bits_to_set);
    test_count_any_none_all();
}

TEST_F(Bitset23Bit, BitwiseAnd) {
    std::vector<std::size_t> bits_to_set{3, 4, 5, 8, 9};
    set_bits(bits_to_set);
    test_bitwise_and();
}

TEST_F(Bitset23Bit, BitwiseOR) {
    std::vector<std::size_t> bits_to_set{13, 14, 15, 16, 20};
    set_bits(bits_to_set);
    test_bitwise_or();
}

TEST_F(Bitset23Bit, BitwiseXOR) {
    std::vector<std::size_t> bits_to_set{0, 5, 6, 7, 21, 22};
    set_bits(bits_to_set);
    test_bitwise_xor();
}

TEST_F(Bitset23Bit, BitwiseNOT) {
    std::vector<std::size_t> bits_to_set{11, 12, 13, 14, 15, 16};
    set_bits(bits_to_set);
    test_bitwise_not();
}

TEST_F(Bitset23Bit, ShiftLeft) {
    std::string bits = "1010101101001010010110";
    bitset = Bitset<23>(bits);
    std_bitset = std::bitset<23>(bits);
    test_shift_left(13);
    test_shift_left_assign(15);
}

TEST_F(Bitset23Bit, ShifRight) {
    std::string bits = "11111001010001010010101010100111"; 
    bitset = Bitset<23>(bits);
    std_bitset = std::bitset<23>(bits);;
    test_shift_right(18);
    test_shift_right_assign(7);
}

TEST_F(Bitset23Bit, SubscriptOperators) {
    test_non_const_subscript(10, true);  
    test_non_const_subscript(21, false);
    test_non_const_subscript(22, false);

    std::string bits = "100101001001010100110";
    const Bitset<23> const_bitset(bits);
    test_const_subscript(const_bitset, 0, false);
    test_const_subscript(const_bitset, 1, true);
    test_const_subscript(const_bitset, 2, true);
}

TEST_F(Bitset23Bit, Equality) {
    std::string bits = "101010010101101010011";
    Bitset<23> other1(bits);
    Bitset<23> other2(bits);
    EXPECT_FALSE(bitset == other1);
    EXPECT_TRUE(other1 == other2);
}

TEST_F(Bitset23Bit, Inequality) {
    std::string bits = "10111010101010001010101";
    Bitset<23> other1(bits);
    Bitset<23> other2(bits);
    EXPECT_TRUE(bitset != other1);
    EXPECT_FALSE(other1 != other2);
}

TEST_F(Bitset23Bit, ToUlong) {
    std::string bits = "10001111111111111111";
    bitset = Bitset<23>(bits);
    std_bitset = std::bitset<23>(bits);;
    test_to_ulong();
}

TEST_F(Bitset23Bit, ToString) {
    std::string bits = "101011010101001001111";
    bitset = Bitset<23>(bits);
    std_bitset = std::bitset<23>(bits);;
    test_to_string();
}

TEST_F(Bitset23Bit, OutputStream) {
    std::string bits = "11101010101101010101010101";
    Bitset<23> other_bitset(bits);
    std::bitset<23> other_std(bits);
    bitset = other_bitset;
    std_bitset = other_std;
    test_output_stream();
}

