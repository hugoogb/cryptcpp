#pragma once

#include <string>
#include <vector>

namespace cryptcpp {

struct MessageRecord {
  std::string plain_text;
  std::string cipher_text;
  std::string method;
  std::string key;
};

class MessageStore {
public:
  void add(MessageRecord record);
  const std::vector<MessageRecord> &records() const;
  std::size_t size() const;

private:
  std::vector<MessageRecord> records_;
};

} // namespace cryptcpp
