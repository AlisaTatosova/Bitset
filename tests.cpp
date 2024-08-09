#include <iostream>
#include <bitset>
#include "bitset.h"

// test1 (set, reset)
void test_set_reset() {
    Bitset<9> my_bs;
    std::cout << "Bitset: " << my_bs << std::endl;
    my_bs.set(1, true);
    my_bs.set(3);
    my_bs.set(5);
    std::cout << "Bitset after seting bits 1, 3, 5: " << my_bs.to_string() << std::endl;
    my_bs.reset(3);
    std::cout << "Bitset after reseting bit 3: " << my_bs.to_string() << std::endl;
}

// test2 (set, flip, to_string, to_ulong)
void test_flip_to_string_to_ulong() {
    Bitset<16> my_bs(135);
    std::cout << "Bitset: " << my_bs << std::endl;
    my_bs.flip(0);
    my_bs.set(1);
    my_bs.flip(2);
    my_bs.set(3, true);
    std::cout << "Bitset after fliping bits 0, 2 and setting bits 1, 3: "  << my_bs.to_string() <<  std::endl;
    std::cout << "Converted to unsigned long: " << my_bs.to_ulong() << std::endl;
}

// test3 (constructor with string)
void test_ctor_with_string() {
    Bitset<8> my_bs2("10101101");
    std::bitset<8> test_bs2("10101101");
    std::cout << my_bs2.to_ulong() << " " << my_bs2  << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs2.to_ulong() << " " << test_bs2 << " : Bitset of std" << std::endl;

    Bitset<8> my_bs3("101");
    std::bitset<8> test_bs3("101");
    std::cout << my_bs3.to_ulong() << " " << my_bs3  << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs3.to_ulong() << " " << test_bs3 << " : Bitset of std" << std::endl;

    Bitset<4> my_bs4("1011001101");
    std::bitset<4> test_bs4("1011001101");
    std::cout << my_bs4.to_ulong() << " " << my_bs4  << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs4.to_ulong() << " " << test_bs4 << " : Bitset of std" << std::endl;
}

// test4 (constructor with unsigned int)
void test_ctor_with_unsigned_long_long() {
    unsigned int value = 173; // 173 in binary is 10101101
    Bitset<8> my_bs1(value);
    std::bitset<8> test_bs1(value);
    std::cout << my_bs1.to_ulong() << " " << my_bs1 << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs1.to_ulong() << " " << test_bs1 << " : Bitset of std" << std::endl;

    Bitset<4> my_bs2(value); // 173 in binary is 10101101, has 8 bits, but we preserve in 4
    std::bitset<4> test_bs2(value);
    std::cout << my_bs2.to_ulong() << " " << my_bs2 << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs2.to_ulong() << " " << test_bs2 << " : Bitset of std" << std::endl;

    Bitset<18> my_bs3(-1); 
    std::bitset<18> test_bs3(-1);
    std::cout << my_bs3.to_string() << " " << my_bs3 << " : Implemented Bitset" <<std::endl; 
    std::cout << test_bs3.to_string() << " " << test_bs3 << " : Bitset of std" << std::endl;
}

// test5 (copy and move constructors)
void test_copy_and_move_ctors() {
    Bitset<10> my_bs("1011001101");
    Bitset<10> mybs_copy(my_bs);
    std::cout << "Bitset : " <<  mybs_copy << " copied from " << my_bs <<std::endl; 
    if (mybs_copy == my_bs) {
        std::cout << "Copied successfully!" << std::endl;
    } 

    Bitset<10> my_bs_move = std::move(my_bs);
    std::cout << my_bs_move << " : Moved Bitset" <<std::endl; 
}

// test7 (cppy and move assignments)
void test_copy_and_move_assignments() {
    unsigned int val = 123;
    Bitset<10> my_bs(val);
    Bitset<10> mybs_copy_assign;
    mybs_copy_assign = my_bs;
    std::cout << "Copy assignment from : " <<  my_bs << " to : " << mybs_copy_assign << std::endl;

    Bitset<10> my_bs_move_assign;
    my_bs_move_assign = std::move(my_bs);
    std::cout << "Move assignment in: " << my_bs_move_assign  << std::endl;
}

// test8 (none(), any(), all(), test())
void test_any_none_all_test() {
    Bitset<6> my_bs(63);
    std::cout << "Custom Bitset: " << my_bs.to_string() << std::endl;
    std::cout << "Count of set bits: " << my_bs.count() << std::endl;
    std::cout << "None of the bits set: " << (my_bs.none() ? "Yes" : "No") << std::endl;
    std::cout << "All bits set: " << (my_bs.all() ? "Yes" : "No") << std::endl;
    std::cout << "Any bit set: " << (my_bs.any() ? "Yes" : "No") << std::endl;
    std::cout << "Test bit 3: " << (my_bs.test(3) ? "Set" : "Not Set") << std::endl;
}

// test9 (operator[])
void test_subscript_operator() {
    Bitset<15> my_bs(189);
    std::cout << "Bitset : " << my_bs.to_string() << " " << my_bs.to_ulong() << std::endl;
    std::cout <<  "Bitset's bit at index 0 : " << my_bs[0] << std::endl;
    my_bs[0] = 0;
    std::cout << "Bitset after writing at index 0 : " << my_bs.to_string() << std::endl;
}

// test10 
void test_shifts() {
    Bitset<17> my_bs("10111111111111111");
    std::cout << my_bs.to_string() <<  " : Bitset" <<std::endl;
    my_bs >>= 3;
    std::cout << my_bs.to_string() << " : Bitset after shifting 3 bits right" <<std::endl;
    my_bs <<= 14;
    std::cout << my_bs.to_string() << " : Bitset after shifting left 14 bits" <<std::endl;

    Bitset<32> my_bs2("1011111111111111111111");
    std::cout << my_bs2 << " is shifted right 14 bits : " << (my_bs2 >> 14)  << std::endl;
    std::cout <<  my_bs2 << " is shifted left 2 bits : " << (my_bs2 << 2)  << std::endl;
}

// test11(&, |, ^)
void test_and_or_xor() {
    Bitset<8> bs1("11001100");
    Bitset<8> bs2("10101010");
    Bitset<8> and_result = bs1 & bs2;
    std::cout << bs1 << " & " << bs2  << " : " << and_result << std::endl; // Expected output: 10001000

    Bitset<8> or_result = bs1 | bs2;
    std::cout << bs1 << " | " << bs2  << " : " << or_result << std::endl; // Expected output: 11101110

    Bitset<8> xor_result = bs1 ^ bs2;
    std::cout << bs1 << " ^ " << bs2  << " : " << xor_result << std::endl; // Expected output: 01100110
}

// test12 (&=, |= , ^=, ~)
void test_and_or_xor_assignment() {
    Bitset<8> bitset1;
    bitset1.set(1);
    bitset1.set(3);
    bitset1.set(5);

    Bitset<8> bitset2;
    bitset2.set(3);
    bitset2.set(4);
    bitset2.set(5);

    std::cout << "bitset1: " << bitset1.to_string() << std::endl;
    std::cout << "bitset2: " << bitset2.to_string() << std::endl;
    bitset1 &= bitset2;
    std::cout << bitset1 << " &= " <<  bitset2 << " : " << bitset1.to_string() << std::endl;
    std::cout << bitset1 << " |= " <<  bitset2 << " : ";
    bitset1 |= bitset2;
    std::cout << bitset1.to_string() << std::endl;
    std::cout << bitset1 << " ^= " <<  bitset2 << " : " ;
    bitset1 ^= bitset2;
    std::cout << bitset1.to_string() << std::endl;
    std::cout << "~" << bitset1  << " : " << ~bitset1 << std::endl;  
}

// test13 (istream, ostream)
void test_istream_ostream() {
    Bitset<4> b;
    std::cout << "Enter a 4-bit binary number: ";
    std::cin >> b;
    std::cout << "You entered: " << b << std::endl;
}