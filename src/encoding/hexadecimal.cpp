#include "cryptcpp/encoding/hexadecimal.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace cryptcpp {

std::string Hexadecimal::encrypt(std::string_view input) const {
  std::ostringstream oss;
  oss << std::hex << std::uppercase << std::setfill('0');
  for (unsigned char c : input) {
    oss << std::setw(2) << static_cast<int>(c);
  }
  return oss.str();
}

std::string Hexadecimal::decrypt(std::string_view input) const {
  if (input.size() % 2 != 0)
    throw std::invalid_argument("Invalid hex string length");

  std::string result;
  for (std::size_t i = 0; i < input.size(); i += 2) {
    std::string byte_str(input.substr(i, 2));
    int val = std::stoi(byte_str, nullptr, 16);
    result += static_cast<char>(val);
  }
  return result;
}

std::string Hexadecimal::name() const { return "Hexadecimal"; }

} // namespace cryptcpp
