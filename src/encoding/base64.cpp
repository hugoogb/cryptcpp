#include "cryptcpp/encoding/base64.h"
#include <stdexcept>

namespace cryptcpp {

static constexpr char kAlphabet[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string Base64::encrypt(std::string_view input) const {
  std::string result;
  int val = 0;
  int bits = -6;

  for (unsigned char c : input) {
    val = (val << 8) + c;
    bits += 8;
    while (bits >= 0) {
      result += kAlphabet[(val >> bits) & 0x3F];
      bits -= 6;
    }
  }

  if (bits > -6) {
    result += kAlphabet[(val << (-bits)) & 0x3F];
  }

  while (result.size() % 4 != 0) {
    result += '=';
  }

  return result;
}

std::string Base64::decrypt(std::string_view input) const {
  std::string result;
  int val = 0;
  int bits = -8;

  for (char c : input) {
    if (c == '=')
      break;

    int d = -1;
    if (c >= 'A' && c <= 'Z')
      d = c - 'A';
    else if (c >= 'a' && c <= 'z')
      d = c - 'a' + 26;
    else if (c >= '0' && c <= '9')
      d = c - '0' + 52;
    else if (c == '+')
      d = 62;
    else if (c == '/')
      d = 63;

    if (d < 0)
      throw std::invalid_argument("Invalid Base64 character");

    val = (val << 6) + d;
    bits += 6;
    if (bits >= 0) {
      result += static_cast<char>((val >> bits) & 0xFF);
      bits -= 8;
    }
  }

  return result;
}

std::string Base64::name() const { return "Base64"; }

} // namespace cryptcpp
