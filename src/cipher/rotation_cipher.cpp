#include "cryptcpp/cipher/rotation_cipher.h"

namespace cryptcpp {

RotationCipher::RotationCipher(int shift) : shift_(((shift % 26) + 26) % 26) {}

std::string RotationCipher::encrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());

  for (char c : input) {
    if (c >= 'A' && c <= 'Z') {
      result += static_cast<char>((c - 'A' + shift_) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
      result += static_cast<char>((c - 'a' + shift_) % 26 + 'a');
    } else {
      result += c;
    }
  }

  return result;
}

std::string RotationCipher::decrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());

  for (char c : input) {
    if (c >= 'A' && c <= 'Z') {
      result += static_cast<char>(((c - 'A' - shift_) % 26 + 26) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
      result += static_cast<char>(((c - 'a' - shift_) % 26 + 26) % 26 + 'a');
    } else {
      result += c;
    }
  }

  return result;
}

std::string RotationCipher::name() const {
  if (shift_ == 3)
    return "Caesar";
  if (shift_ == 13)
    return "ROT13";
  return "ROT" + std::to_string(shift_);
}

RotationCipher RotationCipher::caesar() { return RotationCipher(3); }

RotationCipher RotationCipher::rot13() { return RotationCipher(13); }

} // namespace cryptcpp
