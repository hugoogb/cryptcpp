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
#include <memory>
#include <sstream>
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

static std::string to_lower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

static void print_usage(const char *prog) {
  std::cerr << "Usage: " << prog
            << " <encrypt|decrypt> <method> [key] [text]" << endl;
  std::cerr << endl;
  std::cerr << "Methods:" << endl;
  std::cerr << "  Ciphers:    caesar, rot13, rot <N>, vigenere <KEY>"
            << endl;
  std::cerr << "  Transforms: reverse, lowercase, uppercase, capitalize, "
               "inversecase"
            << endl;
  std::cerr << "  Encodings:  base32, base64, ascii85, decimal, hex, "
               "binary, octal, url"
            << endl;
  std::cerr << endl;
  std::cerr << "If text is omitted, reads from stdin." << endl;
}

int CliApp::run_oneshot(int argc, char *argv[]) {
  if (argc < 3) {
    print_usage(argv[0]);
    return 1;
  }

  std::string op = to_lower(argv[1]);
  std::string method_name = to_lower(argv[2]);

  bool encrypting;
  if (op == "encrypt")
    encrypting = true;
  else if (op == "decrypt")
    encrypting = false;
  else {
    std::cerr << "Error: operation must be 'encrypt' or 'decrypt'" << endl;
    return 1;
  }

  // Build method and figure out which arg is the text
  std::unique_ptr<ICryptMethod> method;
  int text_arg_index = 3; // index of the text argument in argv

  try {
    if (method_name == "caesar") {
      method = std::make_unique<RotationCipher>(RotationCipher::caesar());
    } else if (method_name == "rot13") {
      method = std::make_unique<RotationCipher>(RotationCipher::rot13());
    } else if (method_name == "rot") {
      if (argc < 4) {
        std::cerr << "Error: 'rot' requires a shift number" << endl;
        return 1;
      }
      int shift;
      try {
        shift = std::stoi(argv[3]);
      } catch (const std::exception &) {
        std::cerr << "Error: invalid shift number '" << argv[3] << "'"
                  << endl;
        return 1;
      }
      method = std::make_unique<RotationCipher>(shift);
      text_arg_index = 4;
    } else if (method_name == "vigenere") {
      if (argc < 4) {
        std::cerr << "Error: 'vigenere' requires a key" << endl;
        return 1;
      }
      method = std::make_unique<VigenereCipher>(argv[3]);
      text_arg_index = 4;
    } else if (method_name == "reverse") {
      method = std::make_unique<Reverse>();
    } else if (method_name == "lowercase") {
      method = std::make_unique<Lowercase>();
    } else if (method_name == "uppercase") {
      method = std::make_unique<Uppercase>();
    } else if (method_name == "capitalize") {
      method = std::make_unique<Capitalize>();
    } else if (method_name == "inversecase") {
      method = std::make_unique<InverseCase>();
    } else if (method_name == "base32") {
      method = std::make_unique<Base32>();
    } else if (method_name == "base64") {
      method = std::make_unique<Base64>();
    } else if (method_name == "ascii85") {
      method = std::make_unique<Ascii85>();
    } else if (method_name == "decimal") {
      method = std::make_unique<Decimal>();
    } else if (method_name == "hex" || method_name == "hexadecimal") {
      method = std::make_unique<Hexadecimal>();
    } else if (method_name == "binary") {
      method = std::make_unique<Binary>();
    } else if (method_name == "octal") {
      method = std::make_unique<Octal>();
    } else if (method_name == "url") {
      method = std::make_unique<Url>();
    } else {
      std::cerr << "Error: unknown method '" << argv[2] << "'" << endl;
      return 1;
    }
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: " << e.what() << endl;
    return 1;
  }

  // Get input text: from argv or stdin
  std::string input;
  if (text_arg_index < argc) {
    input = argv[text_arg_index];
  } else {
    std::ostringstream oss;
    oss << cin.rdbuf();
    input = oss.str();
    // Strip trailing newline from piped input
    if (!input.empty() && input.back() == '\n')
      input.pop_back();
  }

  // Run
  std::string output;
  try {
    output = encrypting ? method->encrypt(input) : method->decrypt(input);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << endl;
    return 1;
  }

  cout << output << endl;
  return 0;
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
           auto [shift, ok] = read_integer();
           if (!ok)
             return;
           RotationCipher m(shift);
           run_method_loop(
               "--- ROT" + std::to_string(shift) + " ---", m,
               std::to_string(shift));
         }},
        {"Vigenere",
         [this]() {
           std::string key = read_text(" - Enter Vigenere key: ");
           try {
             VigenereCipher m(key);
             run_method_loop("--- Vigenere ---", m, key);
           } catch (const std::invalid_argument &e) {
             cout << " - Error: " << e.what() << endl << endl;
           }
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
