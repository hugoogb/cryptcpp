#include "cryptcpp/transform/uppercase.h"
#include <cctype>

namespace cryptcpp {

std::string Uppercase::encrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());
  for (char c : input) {
    result += static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  }
  return result;
}

std::string Uppercase::decrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());
  for (char c : input) {
    result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return result;
}

std::string Uppercase::name() const { return "Uppercase"; }

} // namespace cryptcpp
