#pragma once

#include "cryptcpp/method.h"

namespace cryptcpp {

class Hexadecimal : public ICryptMethod {
public:
  std::string encrypt(std::string_view input) const override;
  std::string decrypt(std::string_view input) const override;
  std::string name() const override;
};

} // namespace cryptcpp
