#pragma once

#include "terminal.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

namespace cryptcpp::cli {

struct MenuItem {
  std::string label;
  std::function<void()> action;
};

// Interactive menu selection. Returns 1-indexed choice.
int select_menu(const std::string &title, const std::vector<MenuItem> &items);

// Interactive encrypt/decrypt selection. Returns 1=Encrypt, 2=Decrypt, 3=Back.
int select_encrypt_decrypt(const std::string &banner);

// Read an integer from stdin (cooked mode).
std::pair<int, bool> read_integer();

} // namespace cryptcpp::cli
