#include <catch2/catch_test_macros.hpp>
#include "cryptcpp/cipher/rotation_cipher.h"

using cryptcpp::RotationCipher;

TEST_CASE("Caesar encrypt known values", "[rotation]") {
  auto caesar = RotationCipher::caesar();
  CHECK(caesar.encrypt("ABC") == "DEF");
  CHECK(caesar.encrypt("XYZ") == "ABC");
  CHECK(caesar.encrypt("abc") == "def");
  CHECK(caesar.encrypt("xyz") == "abc");
}

TEST_CASE("Caesar roundtrip", "[rotation]") {
  auto caesar = RotationCipher::caesar();
  std::string input = "Hello, World! 123";
  CHECK(caesar.decrypt(caesar.encrypt(input)) == input);
}

TEST_CASE("ROT13 known values", "[rotation]") {
  auto rot13 = RotationCipher::rot13();
  CHECK(rot13.encrypt("HELLO") == "URYYB");
  CHECK(rot13.encrypt("hello") == "uryyb");
}

TEST_CASE("ROT13 is its own inverse", "[rotation]") {
  auto rot13 = RotationCipher::rot13();
  std::string input = "Test Message!";
  CHECK(rot13.encrypt(rot13.encrypt(input)) == input);
}

TEST_CASE("Rotation preserves non-alpha", "[rotation]") {
  RotationCipher c(5);
  std::string input = "Hello, World! 123 @#$";
  std::string encrypted = c.encrypt(input);
  CHECK(encrypted.find(',') != std::string::npos);
  CHECK(encrypted.find('!') != std::string::npos);
  CHECK(encrypted.find("123") != std::string::npos);
  CHECK(c.decrypt(encrypted) == input);
}

TEST_CASE("Rotation wrapping", "[rotation]") {
  RotationCipher c(25);
  CHECK(c.encrypt("B") == "A");
  CHECK(c.decrypt("A") == "B");
}

TEST_CASE("Negative modulo regression", "[rotation]") {
  // This was a bug: (cipherText[i] - key - 'A') % 26 could go negative
  RotationCipher c(20);
  std::string input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  CHECK(c.decrypt(c.encrypt(input)) == input);
}

TEST_CASE("Large shift values", "[rotation]") {
  RotationCipher c(29); // equiv to shift 3
  auto caesar = RotationCipher::caesar();
  CHECK(c.encrypt("ABC") == caesar.encrypt("ABC"));
}

TEST_CASE("Negative shift", "[rotation]") {
  RotationCipher c(-3);
  auto caesar = RotationCipher::caesar();
  CHECK(c.encrypt("DEF") == caesar.decrypt("DEF"));
}

TEST_CASE("Empty string", "[rotation]") {
  auto caesar = RotationCipher::caesar();
  CHECK(caesar.encrypt("") == "");
  CHECK(caesar.decrypt("") == "");
}

TEST_CASE("Rotation name", "[rotation]") {
  CHECK(RotationCipher::caesar().name() == "Caesar");
  CHECK(RotationCipher::rot13().name() == "ROT13");
  CHECK(RotationCipher(7).name() == "ROT7");
}
