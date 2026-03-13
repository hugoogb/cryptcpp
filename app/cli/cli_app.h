#pragma once

#include "cryptcpp/message_store.h"
#include "cryptcpp/method.h"
#include <memory>
#include <string>

namespace cryptcpp::cli {

class CliApp {
public:
  void run();

private:
  void handle_transform();
  void handle_cipher();
  void handle_encoding();
  void show_history();
  void run_method_loop(const std::string &banner,
                       const ICryptMethod &method,
                       const std::string &key_display = "");

  MessageStore store_;
};

} // namespace cryptcpp::cli
