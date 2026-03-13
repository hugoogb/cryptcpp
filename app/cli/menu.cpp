#include "menu.h"

#include <iostream>
#include <limits>

namespace cryptcpp::cli {

int select_menu(const std::string &title, const std::vector<MenuItem> &items) {
  std::vector<std::string> labels;
  labels.reserve(items.size());
  for (const auto &item : items)
    labels.push_back(item.label);

  int idx = interactive_select(title, labels);
  if (idx < 0)
    return -1;
  return idx + 1;
}

int select_encrypt_decrypt(const std::string &banner) {
  std::vector<std::string> labels = {"Encrypt", "Decrypt", "Back"};
  int idx = interactive_select(banner, labels);
  if (idx < 0)
    return -1;
  return idx + 1;
}

std::pair<int, bool> read_integer() {
  int val;
  if (!(std::cin >> val)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << " - Invalid input, try again." << std::endl << std::endl;
    return {0, false};
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return {val, true};
}

} // namespace cryptcpp::cli
