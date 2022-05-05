#include <string>

#include "Key.h"

class Message
{
private:
  std::string plain_text;
  std::string cipher_text;
  std::string method_used;
  Key<int> key_used;

public:
  Message();
  Message(std::string plain_text, std::string cipher_text, std::string method_used, std::string key_char_used, int key_int_used);
  ~Message();

  std::string getPlainText() { return plain_text; }
  std::string getCipherText() { return cipher_text; }
  std::string getMethod() { return method_used; }
  std::string getKeyChar() { return key_char_used; }
  int getKeyInt() { return key_int_used; }

  void setPlainText(std::string plain_text) { this->plain_text = plain_text; }
  void setCipherText(std::string cipher_text) { this->cipher_text = cipher_text; }
  void setMethod(std::string method_used) { this->method_used = method_used; }
  void setKeyChar(std::string key_char_used) { this->key_char_used = key_char_used; }
  void setKeyInt(int key_int_used) { this->key_int_used = key_int_used; }
};
