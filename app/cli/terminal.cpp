#include "terminal.h"

#include <iostream>
#include <limits>
#include <termios.h>
#include <unistd.h>

namespace cryptcpp::cli {

// RAII guard: switches stdin to raw mode, restores on destruction.
class RawModeGuard {
public:
  RawModeGuard() : original_{}, valid_(false) {
    if (!isatty(STDIN_FILENO))
      return;
    if (tcgetattr(STDIN_FILENO, &original_) != 0)
      return;
    valid_ = true;

    struct termios raw = original_;
    raw.c_lflag &= ~(ICANON | ECHO | ISIG);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  }

  ~RawModeGuard() {
    if (valid_)
      tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_);
  }

  RawModeGuard(const RawModeGuard &) = delete;
  RawModeGuard &operator=(const RawModeGuard &) = delete;

private:
  struct termios original_;
  bool valid_;
};

KeyEvent read_key() {
  char c;
  if (read(STDIN_FILENO, &c, 1) != 1)
    return {KeyPress::Other, 0};

  if (c == '\n' || c == '\r')
    return {KeyPress::Enter, 0};

  if (c == 3) // Ctrl-C
    return {KeyPress::Quit, 0};

  if (c == 'q' || c == 'Q')
    return {KeyPress::Quit, 0};

  if (c >= '1' && c <= '9')
    return {KeyPress::Digit, c - '0'};

  // Escape sequence (arrow keys)
  if (c == '\033') {
    char seq[2];
    if (read(STDIN_FILENO, &seq[0], 1) != 1)
      return {KeyPress::Other, 0};
    if (read(STDIN_FILENO, &seq[1], 1) != 1)
      return {KeyPress::Other, 0};
    if (seq[0] == '[') {
      if (seq[1] == 'A')
        return {KeyPress::ArrowUp, 0};
      if (seq[1] == 'B')
        return {KeyPress::ArrowDown, 0};
    }
    return {KeyPress::Other, 0};
  }

  // Vim-style navigation
  if (c == 'k')
    return {KeyPress::ArrowUp, 0};
  if (c == 'j')
    return {KeyPress::ArrowDown, 0};

  return {KeyPress::Other, 0};
}

static void clear_lines(int n) {
  for (int i = 0; i < n; ++i)
    std::cout << "\033[2K\n";
  std::cout << "\033[" << n << "A\r";
  std::cout.flush();
}

static int fallback_select(const std::string &title,
                           const std::vector<std::string> &labels) {
  std::string bar(title.size() + 4, '-');
  std::cout << "\t" << bar << "\n";
  std::cout << "\t| " << title << " |\n";
  std::cout << "\t" << bar << "\n";
  for (std::size_t i = 0; i < labels.size(); ++i)
    std::cout << (i + 1) << ". " << labels[i] << "\n";
  std::cout << " - Pick an option: ";

  int val;
  if (!(std::cin >> val)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return -1;
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (val < 1 || val > static_cast<int>(labels.size()))
    return -1;
  return val - 1;
}

int interactive_select(const std::string &title,
                       const std::vector<std::string> &labels) {
  if (labels.empty())
    return -1;

  if (!isatty(STDIN_FILENO))
    return fallback_select(title, labels);

  RawModeGuard guard;
  int selected = 0;
  int count = static_cast<int>(labels.size());

  // 3 lines for title bar + count items + 1 blank + 1 help line
  int total_lines = 3 + count + 2;

  auto render = [&]() {
    std::string bar(title.size() + 4, '-');
    std::cout << "\t" << bar << "\n";
    std::cout << "\t| " << title << " |\n";
    std::cout << "\t" << bar << "\n";

    for (int i = 0; i < count; ++i) {
      std::cout << "\033[2K"; // clear entire line before writing
      if (i == selected)
        std::cout << "\033[7m > " << labels[i] << " \033[0m\n";
      else
        std::cout << "   " << labels[i] << "\n";
    }
    std::cout << "\n [Up/Down] Navigate  [Enter] Select  [q] Back\n";
    std::cout.flush();
  };

  render();

  while (true) {
    KeyEvent key = read_key();

    switch (key.type) {
    case KeyPress::ArrowUp:
      selected = (selected - 1 + count) % count;
      break;
    case KeyPress::ArrowDown:
      selected = (selected + 1) % count;
      break;
    case KeyPress::Enter:
      // Move up and clear the menu area
      std::cout << "\033[" << total_lines << "A\r";
      clear_lines(total_lines);
      return selected;
    case KeyPress::Digit:
      if (key.digit >= 1 && key.digit <= count) {
        std::cout << "\033[" << total_lines << "A\r";
        clear_lines(total_lines);
        return key.digit - 1;
      }
      break;
    case KeyPress::Quit:
      std::cout << "\033[" << total_lines << "A\r";
      clear_lines(total_lines);
      return count - 1; // Last item (Back/Exit)
    default:
      break;
    }

    // Move cursor up to re-render in place
    std::cout << "\033[" << total_lines << "A\r";
    render();
  }
}

} // namespace cryptcpp::cli
