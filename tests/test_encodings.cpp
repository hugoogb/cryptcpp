#include <catch2/catch_test_macros.hpp>
#include "cryptcpp/encoding/ascii85.h"
#include "cryptcpp/encoding/base32.h"
#include "cryptcpp/encoding/base64.h"
#include "cryptcpp/encoding/binary.h"
#include "cryptcpp/encoding/decimal.h"
#include "cryptcpp/encoding/hexadecimal.h"
#include "cryptcpp/encoding/octal.h"
#include "cryptcpp/encoding/url.h"

using namespace cryptcpp;

// --- Base64 ---

TEST_CASE("Base64 RFC 4648 test vectors", "[encoding]") {
  Base64 b;
  CHECK(b.encrypt("") == "");
  CHECK(b.encrypt("f") == "Zg==");
  CHECK(b.encrypt("fo") == "Zm8=");
  CHECK(b.encrypt("foo") == "Zm9v");
  CHECK(b.encrypt("foob") == "Zm9vYg==");
  CHECK(b.encrypt("fooba") == "Zm9vYmE=");
  CHECK(b.encrypt("foobar") == "Zm9vYmFy");
}

TEST_CASE("Base64 known value", "[encoding]") {
  Base64 b;
  CHECK(b.encrypt("Hello") == "SGVsbG8=");
}

TEST_CASE("Base64 roundtrip", "[encoding]") {
  Base64 b;
  std::string input = "Hello, World! 123";
  CHECK(b.decrypt(b.encrypt(input)) == input);
}

TEST_CASE("Base64 decode", "[encoding]") {
  Base64 b;
  CHECK(b.decrypt("SGVsbG8=") == "Hello");
}

// --- Base32 ---

TEST_CASE("Base32 RFC 4648 test vectors", "[encoding]") {
  Base32 b;
  CHECK(b.encrypt("") == "");
  CHECK(b.encrypt("f") == "MY======");
  CHECK(b.encrypt("fo") == "MZXQ====");
  CHECK(b.encrypt("foo") == "MZXW6===");
  CHECK(b.encrypt("foob") == "MZXW6YQ=");
  CHECK(b.encrypt("fooba") == "MZXW6YTB");
  CHECK(b.encrypt("foobar") == "MZXW6YTBOI======");
}

TEST_CASE("Base32 roundtrip", "[encoding]") {
  Base32 b;
  std::string input = "Hello, World!";
  CHECK(b.decrypt(b.encrypt(input)) == input);
}

// --- Ascii85 ---

TEST_CASE("Ascii85 roundtrip", "[encoding]") {
  Ascii85 a;
  std::string input = "Hello, World!";
  CHECK(a.decrypt(a.encrypt(input)) == input);
}

TEST_CASE("Ascii85 empty", "[encoding]") {
  Ascii85 a;
  CHECK(a.encrypt("") == "<~~>");
}

TEST_CASE("Ascii85 four null bytes", "[encoding]") {
  Ascii85 a;
  std::string input(4, '\0');
  std::string encoded = a.encrypt(input);
  CHECK(encoded == "<~z~>");
  CHECK(a.decrypt(encoded) == input);
}

// --- Decimal ---

TEST_CASE("Decimal encode", "[encoding]") {
  Decimal d;
  CHECK(d.encrypt("A") == "65");
  CHECK(d.encrypt("AB") == "65 66");
  CHECK(d.encrypt(" ") == "32");
}

TEST_CASE("Decimal roundtrip", "[encoding]") {
  Decimal d;
  std::string input = "Hello!";
  CHECK(d.decrypt(d.encrypt(input)) == input);
}

// --- Hexadecimal ---

TEST_CASE("Hexadecimal encode", "[encoding]") {
  Hexadecimal h;
  CHECK(h.encrypt("A") == "41");
  CHECK(h.encrypt("AB") == "4142");
  CHECK(h.encrypt("Hello") == "48656C6C6F");
}

TEST_CASE("Hexadecimal roundtrip", "[encoding]") {
  Hexadecimal h;
  std::string input = "Hello, World!";
  CHECK(h.decrypt(h.encrypt(input)) == input);
}

// --- Binary ---

TEST_CASE("Binary encode", "[encoding]") {
  Binary b;
  CHECK(b.encrypt("A") == "01000001");
  CHECK(b.encrypt("AB") == "01000001 01000010");
}

TEST_CASE("Binary roundtrip", "[encoding]") {
  Binary b;
  std::string input = "Hello!";
  CHECK(b.decrypt(b.encrypt(input)) == input);
}

// --- Octal ---

TEST_CASE("Octal encode", "[encoding]") {
  Octal o;
  CHECK(o.encrypt("A") == "101");
  CHECK(o.encrypt("AB") == "101 102");
}

TEST_CASE("Octal roundtrip", "[encoding]") {
  Octal o;
  std::string input = "Hello, World!";
  CHECK(o.decrypt(o.encrypt(input)) == input);
}

// --- URL ---

TEST_CASE("URL encode", "[encoding]") {
  Url u;
  CHECK(u.encrypt("Hello World") == "Hello%20World");
  CHECK(u.encrypt("a+b=c") == "a%2Bb%3Dc");
}

TEST_CASE("URL unreserved chars preserved", "[encoding]") {
  Url u;
  CHECK(u.encrypt("abc-._~123") == "abc-._~123");
}

TEST_CASE("URL roundtrip", "[encoding]") {
  Url u;
  std::string input = "Hello, World! @#$%^&*()";
  CHECK(u.decrypt(u.encrypt(input)) == input);
}
