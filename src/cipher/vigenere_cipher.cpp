#include "cryptcpp/cipher/vigenere_cipher.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace cryptcpp {

VigenereCipher::VigenereCipher(std::string key) : key_(std::move(key)) {
  if (key_.empty())
    throw std::invalid_argument("Vigenere key cannot be empty");
  bool all_alpha = std::all_of(
      key_.begin(), key_.end(),
      [](char c) { return std::isalpha(static_cast<unsigned char>(c)); });
  if (!all_alpha)
    throw std::invalid_argument("Vigenere key must contain only letters");
}

std::string VigenereCipher::expand_key(std::string_view text) const {
  std::string expanded;
  expanded.reserve(text.size());

  std::size_t ki = 0;
  for (std::size_t i = 0; i < text.size(); ++i) {
    char c = text[i];
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      expanded += key_[ki % key_.size()];
      ++ki;
    } else {
      expanded += 'A'; // placeholder for non-alpha (won't be used)
    }
  }

  return expanded;
}

std::string VigenereCipher::encrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());

  std::string full_key = expand_key(input);

  for (std::size_t i = 0; i < input.size(); ++i) {
    char c = input[i];
    char k = full_key[i];

    // Normalize key to 0-25
    int shift = 0;
    if (k >= 'A' && k <= 'Z')
      shift = k - 'A';
    else if (k >= 'a' && k <= 'z')
      shift = k - 'a';

    if (c >= 'A' && c <= 'Z') {
      result += static_cast<char>((c - 'A' + shift) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
      result += static_cast<char>((c - 'a' + shift) % 26 + 'a');
    } else {
      result += c;
    }
  }

  return result;
}

std::string VigenereCipher::decrypt(std::string_view input) const {
  std::string result;
  result.reserve(input.size());

  // Fix: expand key from ciphertext, not empty plaintext
  std::string full_key = expand_key(input);

  for (std::size_t i = 0; i < input.size(); ++i) {
    char c = input[i];
    char k = full_key[i];

    int shift = 0;
    if (k >= 'A' && k <= 'Z')
      shift = k - 'A';
    else if (k >= 'a' && k <= 'z')
      shift = k - 'a';

    if (c >= 'A' && c <= 'Z') {
      result +=
          static_cast<char>(((c - 'A' - shift) % 26 + 26) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
      result +=
          static_cast<char>(((c - 'a' - shift) % 26 + 26) % 26 + 'a');
    } else {
      result += c;
    }
  }

  return result;
}

std::string VigenereCipher::name() const { return "Vigenere"; }

const std::string &VigenereCipher::key() const { return key_; }

} // namespace cryptcpp
