include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(cryptcpp_tests
  test_rotation_cipher.cpp
  test_vigenere_cipher.cpp
  test_transforms.cpp
  test_encodings.cpp
  test_message_store.cpp
)

target_link_libraries(cryptcpp_tests PRIVATE cryptcpp_lib Catch2::Catch2WithMain)

catch_discover_tests(cryptcpp_tests)
