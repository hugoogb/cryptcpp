#include <catch2/catch_test_macros.hpp>
#include "cryptcpp/cipher/vigenere_cipher.h"

using cryptcpp::VigenereCipher;

TEST_CASE("Vigenere roundtrip", "[vigenere]") {
  VigenereCipher v("KEY");
  std::string input = "HELLO WORLD";
  CHECK(v.decrypt(v.encrypt(input)) == input);
}

TEST_CASE("Vigenere lowercase roundtrip", "[vigenere]") {
  VigenereCipher v("secret");
  std::string input = "hello world";
  CHECK(v.decrypt(v.encrypt(input)) == input);
}

TEST_CASE("Vigenere mixed case roundtrip", "[vigenere]") {
  VigenereCipher v("Key");
  std::string input = "Hello World!";
  CHECK(v.decrypt(v.encrypt(input)) == input);
}

TEST_CASE("Vigenere key expansion", "[vigenere]") {
  VigenereCipher v("AB");
  // A shifts by 0, B shifts by 1
  CHECK(v.encrypt("AA") == "AB");
  CHECK(v.encrypt("AAAA") == "ABAB");
}

TEST_CASE("Vigenere decrypt key from ciphertext regression", "[vigenere]") {
  // Bug #9: old code used empty plainText for key gen in decrypt
  VigenereCipher v("SECRET");
  std::string original = "ATTACKATDAWN";
  std::string encrypted = v.encrypt(original);
  CHECK(v.decrypt(encrypted) == original);
}

TEST_CASE("Vigenere preserves non-alpha", "[vigenere]") {
  VigenereCipher v("KEY");
  std::string input = "Hello, World! 123";
  std::string encrypted = v.encrypt(input);
  // Non-alpha chars preserved
  CHECK(encrypted.find(',') != std::string::npos);
  CHECK(encrypted.find('!') != std::string::npos);
  CHECK(encrypted.find("123") != std::string::npos);
  CHECK(v.decrypt(encrypted) == input);
}

TEST_CASE("Vigenere empty string", "[vigenere]") {
  VigenereCipher v("KEY");
  CHECK(v.encrypt("") == "");
  CHECK(v.decrypt("") == "");
}

TEST_CASE("Vigenere name", "[vigenere]") {
  VigenereCipher v("K");
  CHECK(v.name() == "Vigenere");
}

TEST_CASE("Vigenere key accessor", "[vigenere]") {
  VigenereCipher v("MYKEY");
  CHECK(v.key() == "MYKEY");
}
