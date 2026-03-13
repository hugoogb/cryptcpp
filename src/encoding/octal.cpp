#include "cryptcpp/encoding/octal.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace cryptcpp {

std::string Octal::encrypt(std::string_view input) const {
  std::string result;
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (i > 0)
      result += ' ';
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(3) << std::oct
        << static_cast<int>(static_cast<unsigned char>(input[i]));
    result += oss.str();
  }
  return result;
}

std::string Octal::decrypt(std::string_view input) const {
  std::string result;
  std::istringstream stream{std::string(input)};
  std::string token;
  while (stream >> token) {
    int val = std::stoi(token, nullptr, 8);
    if (val < 0 || val > 255)
      throw std::invalid_argument("Invalid octal value");
    result += static_cast<char>(val);
  }
  return result;
}

std::string Octal::name() const { return "Octal"; }

} // namespace cryptcpp
