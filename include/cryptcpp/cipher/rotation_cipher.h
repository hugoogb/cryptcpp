#pragma once

#include "cryptcpp/method.h"

namespace cryptcpp {

class RotationCipher : public ICryptMethod {
public:
  explicit RotationCipher(int shift);

  std::string encrypt(std::string_view input) const override;
  std::string decrypt(std::string_view input) const override;
  std::string name() const override;

  static RotationCipher caesar();
  static RotationCipher rot13();

private:
  int shift_;
};

} // namespace cryptcpp
