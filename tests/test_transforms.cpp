#include <catch2/catch_test_macros.hpp>
#include "cryptcpp/transform/capitalize.h"
#include "cryptcpp/transform/inverse_case.h"
#include "cryptcpp/transform/lowercase.h"
#include "cryptcpp/transform/reverse.h"
#include "cryptcpp/transform/uppercase.h"

using namespace cryptcpp;

// --- Reverse ---

TEST_CASE("Reverse encrypt", "[transform]") {
  Reverse r;
  CHECK(r.encrypt("Hello") == "olleH");
  CHECK(r.encrypt("abcde") == "edcba");
}

TEST_CASE("Reverse roundtrip", "[transform]") {
  Reverse r;
  CHECK(r.decrypt(r.encrypt("Hello World")) == "Hello World");
}

TEST_CASE("Reverse empty", "[transform]") {
  Reverse r;
  CHECK(r.encrypt("") == "");
}

TEST_CASE("Reverse single char", "[transform]") {
  Reverse r;
  CHECK(r.encrypt("A") == "A");
}

// --- Lowercase ---

TEST_CASE("Lowercase encrypt", "[transform]") {
  Lowercase l;
  CHECK(l.encrypt("HELLO") == "hello");
  CHECK(l.encrypt("Hello World") == "hello world");
}

TEST_CASE("Lowercase decrypt produces uppercase", "[transform]") {
  Lowercase l;
  CHECK(l.decrypt("hello") == "HELLO");
}

TEST_CASE("Lowercase empty", "[transform]") {
  Lowercase l;
  CHECK(l.encrypt("") == "");
}

// --- Uppercase ---

TEST_CASE("Uppercase encrypt", "[transform]") {
  Uppercase u;
  CHECK(u.encrypt("hello") == "HELLO");
  CHECK(u.encrypt("Hello World") == "HELLO WORLD");
}

TEST_CASE("Uppercase decrypt produces lowercase", "[transform]") {
  Uppercase u;
  CHECK(u.decrypt("HELLO") == "hello");
}

TEST_CASE("Uppercase empty", "[transform]") {
  Uppercase u;
  CHECK(u.encrypt("") == "");
}

// --- Capitalize ---

TEST_CASE("Capitalize encrypt", "[transform]") {
  Capitalize c;
  CHECK(c.encrypt("hello") == "Hello");
  CHECK(c.encrypt("HELLO") == "HELLO");
}

TEST_CASE("Capitalize decrypt", "[transform]") {
  Capitalize c;
  CHECK(c.decrypt("Hello") == "hello");
}

TEST_CASE("Capitalize empty", "[transform]") {
  Capitalize c;
  CHECK(c.encrypt("") == "");
  CHECK(c.decrypt("") == "");
}

TEST_CASE("Capitalize single char", "[transform]") {
  Capitalize c;
  CHECK(c.encrypt("a") == "A");
  CHECK(c.decrypt("A") == "a");
}

// --- Inverse Case ---

TEST_CASE("InverseCase encrypt", "[transform]") {
  InverseCase ic;
  CHECK(ic.encrypt("Hello") == "hELLO");
  CHECK(ic.encrypt("ABC") == "abc");
  CHECK(ic.encrypt("abc") == "ABC");
}

TEST_CASE("InverseCase is its own inverse", "[transform]") {
  InverseCase ic;
  std::string input = "Hello World!";
  CHECK(ic.encrypt(ic.encrypt(input)) == input);
}

TEST_CASE("InverseCase empty", "[transform]") {
  InverseCase ic;
  CHECK(ic.encrypt("") == "");
}

TEST_CASE("InverseCase preserves non-alpha", "[transform]") {
  InverseCase ic;
  CHECK(ic.encrypt("123!@#") == "123!@#");
}
