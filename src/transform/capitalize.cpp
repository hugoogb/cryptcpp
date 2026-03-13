#include "cryptcpp/transform/capitalize.h"
#include <cctype>

namespace cryptcpp {

std::string Capitalize::encrypt(std::string_view input) const {
  if (input.empty())
    return {};
  std::string result(input);
  result[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[0])));
  return result;
}

std::string Capitalize::decrypt(std::string_view input) const {
  if (input.empty())
    return {};
  std::string result(input);
  result[0] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[0])));
  return result;
}

std::string Capitalize::name() const { return "Capitalize"; }

} // namespace cryptcpp
