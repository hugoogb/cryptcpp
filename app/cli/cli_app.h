#pragma once

#include "cryptcpp/message_store.h"
#include "cryptcpp/method.h"
#include <string>

namespace cryptcpp::cli {

class CliApp {
public:
  void run();

private:
  void show_history();
  void run_method_loop(const std::string &banner,
                       const ICryptMethod &method,
                       const std::string &key_display = "");
  void run_submenu(const std::string &title,
                   std::vector<struct MenuItem> &items);

  MessageStore store_;
};

} // namespace cryptcpp::cli
