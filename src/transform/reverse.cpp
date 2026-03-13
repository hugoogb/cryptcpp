#include "cryptcpp/transform/reverse.h"
#include <algorithm>

namespace cryptcpp {

std::string Reverse::encrypt(std::string_view input) const {
  std::string result(input);
  std::reverse(result.begin(), result.end());
  return result;
}

std::string Reverse::decrypt(std::string_view input) const {
  return encrypt(input);
}

std::string Reverse::name() const { return "Reverse"; }

} // namespace cryptcpp
