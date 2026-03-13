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

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace cryptcpp::cli {

using std::cin;
using std::cout;
using std::endl;

static void clear_screen() { std::system("clear"); }

static std::string read_text(const std::string &prompt) {
  cout << prompt;
  std::string text;
  std::getline(cin, text);
  return text;
}

static std::string truncate(const std::string &s, std::size_t max_len = 60) {
  if (s.size() <= max_len)
    return s;
  return s.substr(0, max_len) + "...";
}

void CliApp::run_submenu(const std::string &title,
                         std::vector<MenuItem> &items) {
  int choice = 0;
  int back = static_cast<int>(items.size());
  do {
    show_menu(title, items);
    choice = read_menu_choice(back);
    if (choice >= 1 && choice < back) {
      clear_screen();
      items[static_cast<std::size_t>(choice - 1)].action();
    }
  } while (choice != back);
  clear_screen();
}

void CliApp::run_method_loop(const std::string &banner,
                             const ICryptMethod &method,
                             const std::string &key_display) {
  int option = 0;
  do {
    menu_encrypt_decrypt(banner);
    option = read_menu_choice(3);

    if (option == 1 || option == 2) {
      bool encrypting = (option == 1);
      std::string prompt = encrypting ? " - Enter text to encrypt: "
                                      : " - Enter text to decrypt: ";
      std::string input = read_text(prompt);

      if (input.empty()) {
        cout << " - Empty input, skipped." << endl << endl;
        continue;
      }

      std::string output;
      try {
        output =
            encrypting ? method.encrypt(input) : method.decrypt(input);
      } catch (const std::exception &e) {
        cout << " - Error: " << e.what() << endl << endl;
        continue;
      }

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

void CliApp::show_history() {
  const auto &records = store_.records();
  if (records.empty()) {
    cout << " No messages yet." << endl << endl;
    cout << "Press Enter to continue...";
    cin.get();
    return;
  }

  std::string bar(19, '-');
  cout << "\t" << bar << endl;
  cout << "\t| Messages History |" << endl;
  cout << "\t" << bar << endl;

  for (std::size_t i = 0; i < records.size(); ++i) {
    const auto &r = records[i];
    cout << " #" << (i + 1) << " [" << r.method;
    if (!r.key.empty())
      cout << ", key=" << r.key;
    cout << "]" << endl;
    cout << "    Plain:  " << truncate(r.plain_text) << endl;
    cout << "    Cipher: " << truncate(r.cipher_text) << endl;
  }
  cout << endl;
  cout << "1. Clear history" << endl;
  cout << "2. Back" << endl;
  cout << " - Pick an option: ";

  int choice = read_menu_choice(2);
  if (choice == 1) {
    store_.clear();
    cout << " - History cleared." << endl << endl;
    cout << "Press Enter to continue...";
    cin.get();
  }
}

void CliApp::run() {
  // --- Transform submenu items ---
  auto make_transform_items = [this]() {
    std::vector<MenuItem> items = {
        {"Reverse",
         [this]() {
           Reverse m;
           run_method_loop("--- Reverse ---", m);
         }},
        {"Lowercase",
         [this]() {
           Lowercase m;
           run_method_loop("--- Lowercase ---", m);
         }},
        {"Uppercase",
         [this]() {
           Uppercase m;
           run_method_loop("--- Uppercase ---", m);
         }},
        {"Capitalize",
         [this]() {
           Capitalize m;
           run_method_loop("--- Capitalize ---", m);
         }},
        {"Inverse case",
         [this]() {
           InverseCase m;
           run_method_loop("--- Inverse Case ---", m);
         }},
        {"Back", []() {}},
    };
    return items;
  };

  // --- Cipher submenu items ---
  auto make_cipher_items = [this]() {
    std::vector<MenuItem> items = {
        {"Caesar",
         [this]() {
           auto m = RotationCipher::caesar();
           run_method_loop("--- Caesar (shift=3) ---", m, "3");
         }},
        {"ROT13",
         [this]() {
           auto m = RotationCipher::rot13();
           run_method_loop("--- ROT13 (shift=13) ---", m, "13");
         }},
        {"ROT_X",
         [this]() {
           cout << " - Enter rotation key (integer): ";
           int shift = read_menu_choice(
               std::numeric_limits<int>::max()); // reuse for int read
           if (shift < 0) {
             // read_menu_choice already printed error
             return;
           }
           RotationCipher m(shift);
           run_method_loop(
               "--- ROT" + std::to_string(shift) + " ---", m,
               std::to_string(shift));
         }},
        {"Vigenere",
         [this]() {
           std::string key = read_text(" - Enter Vigenere key: ");
           if (key.empty()) {
             cout << " - Key cannot be empty." << endl << endl;
             return;
           }
           bool all_alpha = std::all_of(
               key.begin(), key.end(),
               [](char c) { return std::isalpha(static_cast<unsigned char>(c)); });
           if (!all_alpha) {
             cout << " - Key must contain only letters." << endl << endl;
             return;
           }
           VigenereCipher m(key);
           run_method_loop("--- Vigenere ---", m, key);
         }},
        {"Back", []() {}},
    };
    return items;
  };

  // --- Encoding submenu items ---
  auto make_encoding_items = [this]() {
    std::vector<MenuItem> items = {
        {"Base32",
         [this]() {
           Base32 m;
           run_method_loop("--- Base32 ---", m);
         }},
        {"Base64",
         [this]() {
           Base64 m;
           run_method_loop("--- Base64 ---", m);
         }},
        {"Ascii85",
         [this]() {
           Ascii85 m;
           run_method_loop("--- Ascii85 ---", m);
         }},
        {"Decimal",
         [this]() {
           Decimal m;
           run_method_loop("--- Decimal ---", m);
         }},
        {"Hexadecimal",
         [this]() {
           Hexadecimal m;
           run_method_loop("--- Hexadecimal ---", m);
         }},
        {"Binary",
         [this]() {
           Binary m;
           run_method_loop("--- Binary ---", m);
         }},
        {"Octal",
         [this]() {
           Octal m;
           run_method_loop("--- Octal ---", m);
         }},
        {"URL",
         [this]() {
           Url m;
           run_method_loop("--- URL ---", m);
         }},
        {"Back", []() {}},
    };
    return items;
  };

  // --- Main menu ---
  int option = 0;
  do {
    clear_screen();

    std::vector<MenuItem> main_items = {
        {"Transform",
         [&]() {
           clear_screen();
           auto items = make_transform_items();
           run_submenu("Method - Transform", items);
         }},
        {"Ciphers",
         [&]() {
           clear_screen();
           auto items = make_cipher_items();
           run_submenu("Method - Cipher", items);
         }},
        {"Encoding",
         [&]() {
           clear_screen();
           auto items = make_encoding_items();
           run_submenu("Method - Encoding", items);
         }},
        {"Messages history",
         [this]() {
           clear_screen();
           show_history();
         }},
        {"Exit", []() {}},
    };

    show_menu("MENU - Method", main_items);
    option = read_menu_choice(static_cast<int>(main_items.size()));
    if (option >= 1 &&
        option < static_cast<int>(main_items.size())) {
      main_items[static_cast<std::size_t>(option - 1)].action();
    }
  } while (option != 5);

  cout << "Goodbye!" << endl;
}

} // namespace cryptcpp::cli
