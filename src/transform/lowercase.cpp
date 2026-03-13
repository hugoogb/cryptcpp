#include "cryptcpp/transform/lowercase.h"
#include <cctype>

namespace cryptcpp {

std::string Lowercase::encrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());
  for (char c : input) {
    result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return result;
}

std::string Lowercase::decrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());
  for (char c : input) {
    result += static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  }
  return result;
}

std::string Lowercase::name() const { return "Lowercase"; }

} // namespace cryptcpp
