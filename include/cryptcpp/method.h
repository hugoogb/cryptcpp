#pragma once

#include <string>
#include <string_view>

namespace cryptcpp {

class ICryptMethod {
public:
  virtual ~ICryptMethod() = default;
  virtual std::string encrypt(std::string_view input) const = 0;
  virtual std::string decrypt(std::string_view input) const = 0;
  virtual std::string name() const = 0;
};

} // namespace cryptcpp
