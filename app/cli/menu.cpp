#include "menu.h"
#include <iostream>

namespace cryptcpp::cli {

using std::cout;
using std::endl;

void menu_methods() {
  cout << "\t-----------------" << endl;
  cout << "\t| MENU - Method |" << endl;
  cout << "\t-----------------" << endl;
  cout << "1. Transform" << endl;
  cout << "2. Ciphers" << endl;
  cout << "3. Encoding" << endl;
  cout << "4. Messages history" << endl;
  cout << "5. Exit" << endl;
  cout << " - Pick an option: ";
}

void menu_transform() {
  cout << "\t----------------------" << endl;
  cout << "\t| Method - Transform |" << endl;
  cout << "\t----------------------" << endl;
  cout << "1. Reverse" << endl;
  cout << "2. Lowercase" << endl;
  cout << "3. Uppercase" << endl;
  cout << "4. Capitalize" << endl;
  cout << "5. Inverse case" << endl;
  cout << "6. Back" << endl;
  cout << " - Pick an option: ";
}

void menu_cipher() {
  cout << "\t-------------------" << endl;
  cout << "\t| Method - Cipher |" << endl;
  cout << "\t-------------------" << endl;
  cout << "1. Caesar" << endl;
  cout << "2. ROT13" << endl;
  cout << "3. ROT_X" << endl;
  cout << "4. Vigenere" << endl;
  cout << "5. Back" << endl;
  cout << " - Pick an option: ";
}

void menu_encoding() {
  cout << "\t---------------------" << endl;
  cout << "\t| Method - Encoding |" << endl;
  cout << "\t---------------------" << endl;
  cout << "1. Base32" << endl;
  cout << "2. Base64" << endl;
  cout << "3. Ascii85" << endl;
  cout << "4. Decimal" << endl;
  cout << "5. Hexadecimal" << endl;
  cout << "6. Binary" << endl;
  cout << "7. Octal" << endl;
  cout << "8. URL" << endl;
  cout << "9. Back" << endl;
  cout << " - Pick an option: ";
}

void menu_encrypt_decrypt(const std::string &banner) {
  cout << "\t" << banner << endl;
  cout << "1. Encrypt" << endl;
  cout << "2. Decrypt" << endl;
  cout << "3. Back" << endl;
  cout << " - Pick an option: ";
}

} // namespace cryptcpp::cli
