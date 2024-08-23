#include <gtest/gtest.h>
#include "bitset_test.h"

TEST(Constructors7Bit, StringConstructor) {
    std::string bits = "1101010";
    Bitset<7> bitset(bits);
    std::bitset<7> std_bitset(bits);
    EXPECT_EQ(bitset.to_string(), std_bitset.to_string()) << "String Constructor failed";
}

TEST(Constructors7Bit, IntConstructor) {
    unsigned long long num = 122;
    Bitset<7> int_ctor_bitset(num); 
    std::bitset<7> std_int_ctor_bitset(num);
    EXPECT_EQ(int_ctor_bitset.to_string(), std_int_ctor_bitset.to_string()) << "Integer Constructor failed";
}

TEST(Constructors7Bit, CopyConstructor) {
    std::string bits = "1111101";
    Bitset<7> original(bits);
    Bitset<7> copy(original);
    EXPECT_EQ(original.to_string(), copy.to_string()) << "Copy Constructor failed";
}

TEST(Constructors7Bit, MoveConstructor) {
    std::string bits = "1111111";
    Bitset<7> original(bits);
    Bitset<7> copy = original;
    Bitset<7> move_ctor_bitset(std::move(original));
    EXPECT_EQ(move_ctor_bitset.to_string(), copy.to_string()) << "Move Constructor failed";
}

TEST_F(Bitset7Bit, CopyAssignment) {
    std::vector<std::size_t> bits_to_set{1, 2, 4};
    set_bits(bits_to_set);
    test_copy_assignment();
}

TEST_F(Bitset7Bit, MoveAssignment) {
    std::vector<std::size_t> bits_to_set{2, 4};
    set_bits(bits_to_set);
    test_move_assignment();
}

TEST_F(Bitset7Bit, Set) {
    std::vector<std::size_t> bits_to_set{1, 2, 3, 6};
    set_bits(bits_to_set);
    test_set();
}

TEST_F(Bitset7Bit, Reset) {
    std::vector<std::size_t> bits_to_set{0, 2, 5, 6};
    set_bits(bits_to_set);
    std::vector<std::size_t> bits_to_reset{0, 6};
    reset_bits(bits_to_reset);
    test_reset();
}

TEST_F(Bitset7Bit, Flip) {
    std::vector<std::size_t> bits_to_flip{0, 1, 2, 6};
    flip_bits(bits_to_flip);
    test_flip();
}

TEST_F(Bitset7Bit, CountAnyNoneAll) {
    std::vector<std::size_t> bits_to_set{0, 1, 2, 3, 4, 5, 6};
    set_bits(bits_to_set);
    test_count_any_none_all();
}

TEST_F(Bitset7Bit, BitwiseAnd) {
    std::vector<std::size_t> bits_to_set{0, 1, 6};
    set_bits(bits_to_set);
    test_bitwise_and();
}

TEST_F(Bitset7Bit, BitwiseOR) {
    std::vector<std::size_t> bits_to_set{3, 4, 5, 6};
    set_bits(bits_to_set);
    test_bitwise_or();
}

TEST_F(Bitset7Bit, BitwiseXOR) {
    std::vector<std::size_t> bits_to_set{0, 2, 4, 5};
    set_bits(bits_to_set);
    test_bitwise_xor();
}

TEST_F(Bitset7Bit, BitwiseNOT) {
    std::vector<std::size_t> bits_to_set{1, 2, 3};
    set_bits(bits_to_set);
    test_bitwise_not();
}

TEST_F(Bitset7Bit, ShiftLeft) {
    std::string bits = "1010101";
    bitset = Bitset<7>(bits);
    std_bitset = std::bitset<7> (bits);
    test_shift_left(2);
    test_shift_left_assign(4);
}

TEST_F(Bitset7Bit, ShifRight) {
    std::string bits = "1110111";
    bitset = Bitset<7>(bits);
    std_bitset = std::bitset<7> (bits);
    test_shift_right(5);
    test_shift_right_assign(6);
}

TEST_F(Bitset7Bit, SubscriptOperators) {
    test_non_const_subscript(1, true);  
    test_non_const_subscript(4, false);

    std::string bits = "0101010";
    const Bitset<7> const_bitset(bits);
    test_const_subscript(const_bitset, 0, false);
    test_const_subscript(const_bitset, 1, true);
}

TEST_F(Bitset7Bit, Equality) {
    std::string bits = "1010101";
    Bitset<7> other1(bits);
    Bitset<7> other2(bits);
    EXPECT_FALSE(bitset == other1);
    EXPECT_TRUE(other1 == other2);
}

TEST_F(Bitset7Bit, Inequality) {
    std::string bits = "0101010";
    Bitset<7> other1(bits);
    Bitset<7> other2(bits);
    EXPECT_TRUE(bitset != other1);
    EXPECT_FALSE(other1 != other2);
}

TEST_F(Bitset7Bit, ToUlong) {
    std::string bits = "1000111";
    bitset = Bitset<7>(bits);
    std_bitset = std::bitset<7>(bits);;
    test_to_ulong();
}

TEST_F(Bitset7Bit, ToString) {
    std::string bits = "1010110";
    bitset = Bitset<7>(bits);
    std_bitset = std::bitset<7>(bits);;
    test_to_string();
}

TEST_F(Bitset7Bit, OutputStream) {
    std::string bits = "1010101";
    Bitset<7> other_bitset(bits);
    std::bitset<7> std_other(bits);
    bitset = other_bitset;
    std_bitset = std_other;
    test_output_stream();
}


