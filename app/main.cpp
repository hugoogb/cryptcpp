#include "cli/cli_app.h"

int main(int argc, char *argv[]) {
  cryptcpp::cli::CliApp app;
  if (argc > 1)
    return app.run_oneshot(argc, argv);
  app.run();
  return 0;
}
