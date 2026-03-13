#pragma once

#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace cryptcpp::cli {

struct MenuItem {
  std::string label;
  std::function<void()> action;
};

void show_menu(const std::string &title, const std::vector<MenuItem> &items);
int read_menu_choice(int max);
void menu_encrypt_decrypt(const std::string &banner);

} // namespace cryptcpp::cli
