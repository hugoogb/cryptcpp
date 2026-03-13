#include <catch2/catch_test_macros.hpp>
#include "cryptcpp/message_store.h"

using cryptcpp::MessageRecord;
using cryptcpp::MessageStore;

TEST_CASE("MessageStore starts empty", "[store]") {
  MessageStore store;
  CHECK(store.size() == 0);
  CHECK(store.records().empty());
}

TEST_CASE("MessageStore add and retrieve", "[store]") {
  MessageStore store;
  store.add({"plain", "cipher", "Caesar", "3"});
  CHECK(store.size() == 1);
  CHECK(store.records()[0].plain_text == "plain");
  CHECK(store.records()[0].cipher_text == "cipher");
  CHECK(store.records()[0].method == "Caesar");
  CHECK(store.records()[0].key == "3");
}

TEST_CASE("MessageStore multiple records", "[store]") {
  MessageStore store;
  store.add({"a", "b", "ROT13", "13"});
  store.add({"c", "d", "Base64", ""});
  store.add({"e", "f", "Hex", ""});
  CHECK(store.size() == 3);
  CHECK(store.records()[2].plain_text == "e");
}
