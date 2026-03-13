#include "cryptcpp/transform/inverse_case.h"
#include <cctype>

namespace cryptcpp {

std::string InverseCase::encrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());
  for (char c : input) {
    if (std::isupper(static_cast<unsigned char>(c))) {
      result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    } else if (std::islower(static_cast<unsigned char>(c))) {
      result += static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    } else {
      result += c;
    }
  }
  return result;
}

std::string InverseCase::decrypt(std::string_view input) const {
  return encrypt(input);
}

std::string InverseCase::name() const { return "Inverse Case"; }

} // namespace cryptcpp
