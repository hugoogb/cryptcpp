#include "cryptcpp/encoding/base32.h"
#include <stdexcept>

namespace cryptcpp {

static constexpr char kAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

std::string Base32::encrypt(std::string_view input) const {
  std::string result;
  int buffer = 0;
  int bits_left = 0;

  for (unsigned char c : input) {
    buffer = (buffer << 8) | c;
    bits_left += 8;
    while (bits_left >= 5) {
      bits_left -= 5;
      result += kAlphabet[(buffer >> bits_left) & 0x1F];
    }
  }

  if (bits_left > 0) {
    result += kAlphabet[(buffer << (5 - bits_left)) & 0x1F];
  }

  // Pad to multiple of 8
  while (result.size() % 8 != 0) {
    result += '=';
  }

  return result;
}

std::string Base32::decrypt(std::string_view input) const {
  std::string result;
  int buffer = 0;
  int bits_left = 0;

  for (char c : input) {
    if (c == '=')
      break;

    int val = -1;
    if (c >= 'A' && c <= 'Z')
      val = c - 'A';
    else if (c >= '2' && c <= '7')
      val = c - '2' + 26;
    else if (c >= 'a' && c <= 'z')
      val = c - 'a'; // case-insensitive

    if (val < 0)
      throw std::invalid_argument("Invalid Base32 character");

    buffer = (buffer << 5) | val;
    bits_left += 5;
    if (bits_left >= 8) {
      bits_left -= 8;
      result += static_cast<char>((buffer >> bits_left) & 0xFF);
    }
  }

  return result;
}

std::string Base32::name() const { return "Base32"; }

} // namespace cryptcpp
