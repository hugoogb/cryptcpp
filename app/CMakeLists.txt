add_executable(cryptcpp
  main.cpp
  cli/menu.cpp
  cli/cli_app.cpp
)

target_link_libraries(cryptcpp PRIVATE cryptcpp_lib)

target_include_directories(cryptcpp PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(cryptcpp PRIVATE
  -Wall -Wextra -Wpedantic
)

install(TARGETS cryptcpp DESTINATION bin)
