#include "cryptcpp/encoding/ascii85.h"
#include <cstdint>
#include <stdexcept>

namespace cryptcpp {

std::string Ascii85::encrypt(std::string_view input) const {
  std::string result;
  result += "<~";

  std::size_t i = 0;
  while (i < input.size()) {
    uint32_t block = 0;
    int count = 0;
    for (int j = 0; j < 4 && i < input.size(); ++j, ++i) {
      block = (block << 8) | static_cast<unsigned char>(input[i]);
      ++count;
    }

    // Pad remaining bytes with zeros
    block <<= (4 - count) * 8;

    if (count == 4 && block == 0) {
      result += 'z';
    } else {
      char encoded[5];
      for (int j = 4; j >= 0; --j) {
        encoded[j] = static_cast<char>(block % 85 + 33);
        block /= 85;
      }
      // Output count+1 characters
      for (int j = 0; j < count + 1; ++j) {
        result += encoded[j];
      }
    }
  }

  result += "~>";
  return result;
}

std::string Ascii85::decrypt(std::string_view input) const {
  std::string result;

  // Strip <~ and ~> delimiters
  std::string_view data = input;
  if (data.size() >= 2 && data.substr(0, 2) == "<~") {
    data.remove_prefix(2);
  }
  if (data.size() >= 2 && data.substr(data.size() - 2) == "~>") {
    data.remove_suffix(2);
  }

  std::size_t i = 0;
  while (i < data.size()) {
    if (data[i] == 'z') {
      result += std::string(4, '\0');
      ++i;
      continue;
    }

    uint32_t block = 0;
    int count = 0;
    for (int j = 0; j < 5 && i < data.size(); ++j, ++i) {
      if (data[i] < 33 || data[i] > 117) {
        throw std::invalid_argument("Invalid Ascii85 character");
      }
      block = block * 85 + (static_cast<unsigned char>(data[i]) - 33);
      ++count;
    }

    // Pad missing chars with 'u' (value 84)
    for (int j = count; j < 5; ++j) {
      block = block * 85 + 84;
    }

    // Extract count-1 bytes
    int out_bytes = count - 1;
    for (int j = 0; j < out_bytes; ++j) {
      result += static_cast<char>((block >> (24 - j * 8)) & 0xFF);
    }
  }

  return result;
}

std::string Ascii85::name() const { return "Ascii85"; }

} // namespace cryptcpp
