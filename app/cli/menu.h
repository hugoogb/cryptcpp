#pragma once

#include <string>

namespace cryptcpp::cli {

void menu_methods();
void menu_transform();
void menu_cipher();
void menu_encoding();
void menu_encrypt_decrypt(const std::string &banner);

} // namespace cryptcpp::cli
