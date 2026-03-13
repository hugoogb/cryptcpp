#pragma once

#include <string>
#include <vector>

namespace cryptcpp::cli {

enum class KeyPress { ArrowUp, ArrowDown, Enter, Digit, Quit, Other };

struct KeyEvent {
  KeyPress type;
  int digit; // only meaningful when type == Digit
};

// Reads a single key event from stdin in raw mode.
KeyEvent read_key();

// Displays an interactive menu with arrow-key navigation.
// Returns the 0-indexed selected item.
// Falls back to numbered input when stdin is not a tty.
int interactive_select(const std::string &title,
                       const std::vector<std::string> &labels);

} // namespace cryptcpp::cli
