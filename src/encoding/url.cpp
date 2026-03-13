#include "cryptcpp/encoding/url.h"
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace cryptcpp {

static bool is_unreserved(char c) {
  return std::isalnum(static_cast<unsigned char>(c)) || c == '-' || c == '_' ||
         c == '.' || c == '~';
}

std::string Url::encrypt(std::string_view input) const {
  std::ostringstream oss;
  oss << std::hex << std::uppercase << std::setfill('0');
  for (unsigned char c : input) {
    if (is_unreserved(static_cast<char>(c))) {
      oss << static_cast<char>(c);
    } else {
      oss << '%' << std::setw(2) << static_cast<int>(c);
    }
  }
  return oss.str();
}

static int hex_val(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;
  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;
  return -1;
}

std::string Url::decrypt(std::string_view input) const {
  std::string result;
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '%') {
      if (i + 2 >= input.size())
        throw std::invalid_argument("Invalid URL encoding");
      int hi = hex_val(input[i + 1]);
      int lo = hex_val(input[i + 2]);
      if (hi < 0 || lo < 0)
        throw std::invalid_argument("Invalid URL encoding");
      result += static_cast<char>(hi * 16 + lo);
      i += 2;
    } else {
      result += input[i];
    }
  }
  return result;
}

std::string Url::name() const { return "URL"; }

} // namespace cryptcpp
