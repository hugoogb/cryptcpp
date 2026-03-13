#include "cryptcpp/encoding/binary.h"
#include <bitset>
#include <sstream>
#include <stdexcept>

namespace cryptcpp {

std::string Binary::encrypt(std::string_view input) const {
  std::string result;
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (i > 0)
      result += ' ';
    result += std::bitset<8>(static_cast<unsigned char>(input[i])).to_string();
  }
  return result;
}

std::string Binary::decrypt(std::string_view input) const {
  std::string result;
  std::istringstream stream{std::string(input)};
  std::string token;
  while (stream >> token) {
    if (token.size() != 8)
      throw std::invalid_argument("Invalid binary byte");
    int val = std::stoi(token, nullptr, 2);
    result += static_cast<char>(val);
  }
  return result;
}

std::string Binary::name() const { return "Binary"; }

} // namespace cryptcpp
