# cryptcpp

A C++ CLI tool for encrypting and decrypting text using various methods.

## Features

- **Ciphers**: Caesar, ROT13, ROT_X (custom shift), Vigenere
- **Transforms**: Reverse, Lowercase, Uppercase, Capitalize, Inverse case
- **Encodings**: Base32, Base64, Ascii85, Decimal, Hexadecimal, Binary, Octal, URL
- **Message history**: View all encrypt/decrypt operations from the current session
- **Interactive menus**: Arrow-key navigation with highlighted selection (also supports j/k, number shortcuts, and q to go back)

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

### Interactive mode

```sh
./build/app/cryptcpp
```

Navigate menus with arrow keys (or j/k), press Enter to select, and q to go back.

### CLI mode

```sh
./build/app/cryptcpp <encrypt|decrypt> <method> [key] [text]
```

Examples:

```sh
./build/app/cryptcpp encrypt base64 "hello world"
./build/app/cryptcpp decrypt caesar "khoor"
./build/app/cryptcpp encrypt vigenere "key" "hello"
./build/app/cryptcpp encrypt rot 7 "hello"
echo "hello" | ./build/app/cryptcpp encrypt hex
```

## Testing

```sh
cmake -B build -DBUILD_TESTS=ON
cmake --build build
cd build && ctest --output-on-failure
```
