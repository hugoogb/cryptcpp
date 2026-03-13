#include "menu.h"

namespace cryptcpp::cli {

using std::cin;
using std::cout;
using std::endl;

void show_menu(const std::string &title, const std::vector<MenuItem> &items) {
  // Build title bar
  std::string bar(title.size() + 4, '-');
  cout << "\t" << bar << endl;
  cout << "\t| " << title << " |" << endl;
  cout << "\t" << bar << endl;

  for (std::size_t i = 0; i < items.size(); ++i) {
    cout << (i + 1) << ". " << items[i].label << endl;
  }
  cout << " - Pick an option: ";
}

int read_menu_choice(int max) {
  int val;
  if (!(cin >> val)) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << " - Invalid input, try again." << endl << endl;
    return -1;
  }
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (val < 1 || val > max) {
    cout << " - Invalid option, try again." << endl << endl;
    return -1;
  }
  return val;
}

std::pair<int, bool> read_integer() {
  int val;
  if (!(cin >> val)) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << " - Invalid input, try again." << endl << endl;
    return {0, false};
  }
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return {val, true};
}

void menu_encrypt_decrypt(const std::string &banner) {
  cout << "\t" << banner << endl;
  cout << "1. Encrypt" << endl;
  cout << "2. Decrypt" << endl;
  cout << "3. Back" << endl;
  cout << " - Pick an option: ";
}

} // namespace cryptcpp::cli
