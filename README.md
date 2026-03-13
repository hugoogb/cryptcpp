# cryptcpp

A C++ CLI tool for encrypting and decrypting text using various methods.

## Features

- **Ciphers**: Caesar, ROT13, ROT_X (custom shift), Vigenere
- **Transforms**: Reverse, Lowercase, Uppercase, Capitalize, Inverse case
- **Encodings**: Base32, Base64, Ascii85, Decimal, Hexadecimal, Binary, Octal, URL
- **Message history**: View all encrypt/decrypt operations from the current session

## Prerequisites

- CMake 3.16+
- C++17 compiler (GCC, Clang)

## Building

```sh
git clone https://github.com/hugoogb/cryptcpp.git
cd cryptcpp
cmake -B build
cmake --build build
```

## Running

```sh
./build/app/cryptcpp
```

## Testing

```sh
cmake -B build -DBUILD_TESTS=ON
cmake --build build
cd build && ctest --output-on-failure
```
