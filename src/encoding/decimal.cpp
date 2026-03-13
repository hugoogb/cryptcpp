#include "cryptcpp/encoding/decimal.h"
#include <sstream>
#include <stdexcept>

namespace cryptcpp {

std::string Decimal::encrypt(std::string_view input) const {
  std::string result;
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (i > 0)
      result += ' ';
    result += std::to_string(static_cast<unsigned char>(input[i]));
  }
  return result;
}

std::string Decimal::decrypt(std::string_view input) const {
  std::string result;
  std::istringstream stream{std::string(input)};
  int val;
  while (stream >> val) {
    if (val < 0 || val > 255)
      throw std::invalid_argument("Invalid decimal value");
    result += static_cast<char>(val);
  }
  return result;
}

std::string Decimal::name() const { return "Decimal"; }

} // namespace cryptcpp
