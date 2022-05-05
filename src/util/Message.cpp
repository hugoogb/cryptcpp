#include "../../include/util/Message.h"

Message::Message()
{
  plain_text = "";
  cipher_text = "";
  method_used = "";
  key_char_used = "";
  key_int_used = 0;
}

Message::Message(std::string plain_text, std::string cipher_text, std::string method_used, std::string key_char_used, int key_int_used)
{
  this->plain_text = plain_text;
  this->cipher_text = cipher_text;
  this->method_used = method_used;
  this->key_char_used = key_char_used;
  this->key_int_used = key_int_used;
}

Message::~Message()
{
  plain_text = "";
  cipher_text = "";
  method_used = "";
  key_char_used = "";
  key_int_used = 0;
}
