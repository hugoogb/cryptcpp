#pragma once

#include "cryptcpp/method.h"
#include <string>

namespace cryptcpp {

class VigenereCipher : public ICryptMethod {
public:
  explicit VigenereCipher(std::string key);

  std::string encrypt(std::string_view input) const override;
  std::string decrypt(std::string_view input) const override;
  std::string name() const override;

  const std::string &key() const;

private:
  std::string expand_key(std::string_view text) const;
  std::string key_;
};

} // namespace cryptcpp
