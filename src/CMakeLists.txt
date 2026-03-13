add_library(cryptcpp_lib
  cipher/rotation_cipher.cpp
  cipher/vigenere_cipher.cpp
  transform/reverse.cpp
  transform/lowercase.cpp
  transform/uppercase.cpp
  transform/capitalize.cpp
  transform/inverse_case.cpp
  encoding/base32.cpp
  encoding/base64.cpp
  encoding/ascii85.cpp
  encoding/decimal.cpp
  encoding/hexadecimal.cpp
  encoding/binary.cpp
  encoding/octal.cpp
  encoding/url.cpp
  message_store.cpp
)

target_include_directories(cryptcpp_lib PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(cryptcpp_lib PRIVATE
  -Wall -Wextra -Wpedantic
)
