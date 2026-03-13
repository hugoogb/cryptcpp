#include "cryptcpp/message_store.h"

namespace cryptcpp {

void MessageStore::add(MessageRecord record) {
  records_.push_back(std::move(record));
}

void MessageStore::clear() { records_.clear(); }

const std::vector<MessageRecord> &MessageStore::records() const {
  return records_;
}

std::size_t MessageStore::size() const { return records_.size(); }

} // namespace cryptcpp
