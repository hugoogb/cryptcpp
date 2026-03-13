#include "cli_app.h"
#include "menu.h"

#include "cryptcpp/cipher/rotation_cipher.h"
#include "cryptcpp/cipher/vigenere_cipher.h"
#include "cryptcpp/encoding/ascii85.h"
#include "cryptcpp/encoding/base32.h"
#include "cryptcpp/encoding/base64.h"
#include "cryptcpp/encoding/binary.h"
#include "cryptcpp/encoding/decimal.h"
#include "cryptcpp/encoding/hexadecimal.h"
#include "cryptcpp/encoding/octal.h"
#include "cryptcpp/encoding/url.h"
#include "cryptcpp/transform/capitalize.h"
#include "cryptcpp/transform/inverse_case.h"
#include "cryptcpp/transform/lowercase.h"
#include "cryptcpp/transform/reverse.h"
#include "cryptcpp/transform/uppercase.h"

#include <iostream>
#include <limits>
#include <string>

namespace cryptcpp::cli {

using std::cin;
using std::cout;
using std::endl;

static void clear_screen() { std::system("clear"); }

static int read_int() {
  int val;
  if (!(cin >> val)) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return val;
}

static std::string read_text(const std::string &prompt) {
  cout << prompt;
  std::string text;
  std::getline(cin, text);
  return text;
}

void CliApp::run_method_loop(const std::string &banner,
                             const ICryptMethod &method,
                             const std::string &key_display) {
  int option = 0;
  do {
    menu_encrypt_decrypt(banner);
    option = read_int();

    if (option == 1 || option == 2) {
      bool encrypting = (option == 1);
      std::string prompt = encrypting ? " - Enter text to encrypt: "
                                      : " - Enter text to decrypt: ";
      std::string input = read_text(prompt);
      std::string output =
          encrypting ? method.encrypt(input) : method.decrypt(input);

      cout << (encrypting ? " - Encrypted: " : " - Decrypted: ") << output
           << endl;
      cout << endl;

      MessageRecord record;
      if (encrypting) {
        record.plain_text = input;
        record.cipher_text = output;
      } else {
        record.cipher_text = input;
        record.plain_text = output;
      }
      record.method = method.name();
      record.key = key_display;
      store_.add(std::move(record));
    }
  } while (option != 3);
  clear_screen();
}

void CliApp::handle_transform() {
  int option = 0;
  do {
    menu_transform();
    option = read_int();

    switch (option) {
    case 1: {
      clear_screen();
      Reverse m;
      run_method_loop("--- Reverse ---", m);
      break;
    }
    case 2: {
      clear_screen();
      Lowercase m;
      run_method_loop("--- Lowercase ---", m);
      break;
    }
    case 3: {
      clear_screen();
      Uppercase m;
      run_method_loop("--- Uppercase ---", m);
      break;
    }
    case 4: {
      clear_screen();
      Capitalize m;
      run_method_loop("--- Capitalize ---", m);
      break;
    }
    case 5: {
      clear_screen();
      InverseCase m;
      run_method_loop("--- Inverse Case ---", m);
      break;
    }
    }
  } while (option != 6);
  clear_screen();
}

void CliApp::handle_cipher() {
  int option = 0;
  do {
    menu_cipher();
    option = read_int();

    switch (option) {
    case 1: {
      clear_screen();
      auto m = RotationCipher::caesar();
      run_method_loop("--- Caesar (shift=3) ---", m, "3");
      break;
    }
    case 2: {
      clear_screen();
      auto m = RotationCipher::rot13();
      run_method_loop("--- ROT13 (shift=13) ---", m, "13");
      break;
    }
    case 3: {
      clear_screen();
      cout << " - Enter rotation key (integer): ";
      int shift = read_int();
      RotationCipher m(shift);
      run_method_loop("--- ROT" + std::to_string(shift) + " ---", m,
                      std::to_string(shift));
      break;
    }
    case 4: {
      clear_screen();
      std::string key = read_text(" - Enter Vigenere key: ");
      VigenereCipher m(key);
      run_method_loop("--- Vigenere ---", m, key);
      break;
    }
    }
  } while (option != 5);
  clear_screen();
}

void CliApp::handle_encoding() {
  int option = 0;
  do {
    menu_encoding();
    option = read_int();

    switch (option) {
    case 1: {
      clear_screen();
      Base32 m;
      run_method_loop("--- Base32 ---", m);
      break;
    }
    case 2: {
      clear_screen();
      Base64 m;
      run_method_loop("--- Base64 ---", m);
      break;
    }
    case 3: {
      clear_screen();
      Ascii85 m;
      run_method_loop("--- Ascii85 ---", m);
      break;
    }
    case 4: {
      clear_screen();
      Decimal m;
      run_method_loop("--- Decimal ---", m);
      break;
    }
    case 5: {
      clear_screen();
      Hexadecimal m;
      run_method_loop("--- Hexadecimal ---", m);
      break;
    }
    case 6: {
      clear_screen();
      Binary m;
      run_method_loop("--- Binary ---", m);
      break;
    }
    case 7: {
      clear_screen();
      Octal m;
      run_method_loop("--- Octal ---", m);
      break;
    }
    case 8: {
      clear_screen();
      Url m;
      run_method_loop("--- URL ---", m);
      break;
    }
    }
  } while (option != 9);
  clear_screen();
}

void CliApp::show_history() {
  const auto &records = store_.records();
  if (records.empty()) {
    cout << " No messages yet." << endl << endl;
    return;
  }

  cout << "\t---------------------" << endl;
  cout << "\t| Messages History  |" << endl;
  cout << "\t---------------------" << endl;

  for (std::size_t i = 0; i < records.size(); ++i) {
    const auto &r = records[i];
    cout << " #" << (i + 1) << " [" << r.method;
    if (!r.key.empty())
      cout << ", key=" << r.key;
    cout << "]" << endl;
    cout << "    Plain:  " << r.plain_text << endl;
    cout << "    Cipher: " << r.cipher_text << endl;
  }
  cout << endl;
}

void CliApp::run() {
  int option = 0;
  do {
    clear_screen();
    menu_methods();
    option = read_int();

    switch (option) {
    case 1:
      clear_screen();
      handle_transform();
      break;
    case 2:
      clear_screen();
      handle_cipher();
      break;
    case 3:
      clear_screen();
      handle_encoding();
      break;
    case 4:
      clear_screen();
      show_history();
      cout << "Press Enter to continue...";
      cin.get();
      break;
    }
  } while (option != 5);

  cout << "Goodbye!" << endl;
}

} // namespace cryptcpp::cli
