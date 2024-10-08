# Bitset 

This repository contains implementation of a `Bitset`. The `Bitset` class is designed to represent a fixed-size sequence of bits with various operations.

## Build Instructions

1. **Clone the repository**:
    ```sh
    git clone https://github.com/AlisaTatosova/Bitset.git
    cd Bitset
    git submodule update --init --recursive
    ```

2. **Create a build directory**:
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the project**:
    ```sh
    cmake ..
    ```

4. **Build the project**:
    ```sh
    cmake --build .
    ```

This will compile the source files and create an executable named `bitset` and `run_tests`.

## Run the Program

To run the tests, execute the following command from the `build` directory:

```sh
./run_tests
```
To run the main, execute the following command from the `build` directory:

```sh
./bitset
```

## Overview

Below is overview of implementation:

### Data Members

- **bitset**: A dynamic array of `unsigned char` used to store the bits. 
- **length**: Length of this array is determined by the number of bits divided by the number of bits per byte, rounded up.
- **BYTE**: Count of bits in 1 BYTE.

### Logic 
```cpp
// Binary Representation: "00000000.00000000"
// set(0), set(3), set(8) 
bitset[0] = 00001001
bitset[1] = 00000001
```

### Constructors

- **Default Constructor**: Initializes all bits to zero.
- **String Constructor**: Constructs a `Bitset` from a binary string.
- **Integer Constructor**: Initializes the bitset from an `unsigned long long` value by converting the integer to its binary representation.
- **Copy Constructor**: Creates a new `Bitset` as a copy of another bitset.
- **Move Constructor**: Transfers ownership of the internal bit array from another bitset.

### Destructor

- **Destructor**: Cleans up the dynamically allocated memory for the bitset.

### Assignment Operators

- **Copy Assignment**: Assigns the contents of another bitset to this bitset.
- **Move Assignment**: Transfers ownership of the internal bit array from another bitset to this one.

### Bit Manipulation Functions

- **`set(std::size_t pos, bool value = true)`**: Sets the bit at position `pos` to the given value.
- **`reset(std::size_t pos)`**: Resets the bit at position `pos` to 0.
- **`flip(std::size_t pos)`**: Flips the bit at position `pos`.
- **`count()`**: Returns the number of bits set to 1.

### Bitwise Operations

- **AND (`&`)**: Performs a bitwise AND operation with another bitset.
- **OR (`|`)**: Performs a bitwise OR operation with another bitset.
- **XOR (`^`)**: Performs a bitwise XOR operation with another bitset.
- **NOT (`~`)**: Performs a bitwise NOT operation, flipping all bits.
- **AND Assignment (`&=`)**: Performs a bitwise AND assignment with another bitset.
- **OR Assignment (`|=`)**: Performs a bitwise OR assignment with another bitset.
- **XOR Assignment (`^=`)**: Performs a bitwise XOR assignment with another bitset.

### Shift Operators

- **Shift Left (`<<`)**: Shifts the bitset to the left by a specified number of positions, filling with zeros on the right. The result is a new bitset.
- **Shift Right (`>>`)**: Shifts the bitset to the right by a specified number of positions. The result is a new bitset.
- **Shift Left Assignment (`<<=`)**: Shifts the bitset to the left by a specified number of positions, modifying the current bitset.
- **Shift Right Assignment (`>>=`)**: Shifts the bitset to the right by a specified number of positions, modifying the current bitset.


### Comparison Operators

- **Equality (`==`)**: Checks if two bitsets are equal.
- **Inequality (`!=`)**: Checks if two bitsets are not equal.

### Size and Conversion

- **`size()`**: Returns the number of bits in the bitset.
- **`to_ulong()`**: Converts the bitset to an `unsigned long` representation.
- **`to_string()`**: Converts the bitset to a string representation of bits.

### Stream Operators

- **Input (`>>`)**: Reads a binary string from an input stream and initializes the bitset.
- **Output (`<<`)**: Outputs the bitset as a string representation of bits.

