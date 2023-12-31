#include <example/tools.hpp>
#include <example_header_only/tools.hpp>

#include "cli/clilocalsession.h"
#include <cli/boostasioremotecli.h>
#include <cli/boostasioscheduler.h>
#include <cli/cli.h>

#include <iostream>
#include <memory>
#include <ostream>

int main() {
  example::PrintHello();
  example_header_only::PrintHello();

  auto rootMenu = std::make_unique<cli::Menu>("cli");
  rootMenu->Insert(
      "hello", [](std::ostream &out) { out << "Hello, world\n"; },
      "Print hello world");
  rootMenu->Insert(
      "hello_everysession",
      [](std::ostream &) {
        cli::Cli::cout() << "Hello, everybody" << std::endl;
      },
      "Print hello everybody on all open sessions");
  rootMenu->Insert(
      "answer",
      [](std::ostream &out, int x) { out << "The answer is: " << x << "\n"; },
      "Print the answer to Life, the Universe and Everything ");
  rootMenu->Insert(
      "color",
      [](std::ostream &out) {
        out << "Colors ON\n";
        cli::SetColor();
      },
      "Enable colors in the cli");
  rootMenu->Insert(
      "nocolor",
      [](std::ostream &out) {
        out << "Colors OFF\n";
        cli::SetNoColor();
      },
      "Disable colors in the cli");

  auto subMenu = std::make_unique<cli::Menu>("sub");
  subMenu->Insert(
      "hello", [](std::ostream &out) { out << "Hello, submenu world\n"; },
      "Print hello world in the submenu");
  subMenu->Insert(
      "demo", [](std::ostream &out) { out << "This is a sample!\n"; },
      "Print a demo string");

  auto subSubMenu = std::make_unique<cli::Menu>("subsub");
  subSubMenu->Insert(
      "hello", [](std::ostream &out) { out << "Hello, subsubmenu world\n"; },
      "Print hello world in the sub-submenu");
  subMenu->Insert(std::move(subSubMenu));

  rootMenu->Insert(std::move(subMenu));

  cli::Cli cli(std::move(rootMenu));
  // global exit action
  cli.ExitAction(
      [](auto &out) { out << "Goodbye and thanks for all the fish.\n"; });

  cli::BoostAsioScheduler scheduler;
  cli::CliLocalTerminalSession session(cli, scheduler, std::cout, 200);
  session.ExitAction([&scheduler](auto &out) // session exit action
                     {
                       out << "Closing App...\n";
                       scheduler.Stop();
                     });
  cli::BoostAsioCliTelnetServer server(cli, scheduler, "127.0.0.1", 9123, 200);
  server.ExitAction([&scheduler](auto &out) // session exit action
                    {
                      out << "Closing Remote Telnet Session...\n";
                      // scheduler.Stop();
                    });
  try {
    scheduler.Run();
  } catch (std::exception &e) {
    std::cerr << "Exception caugth in main: " << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception caugth in main.\n";
    return 2;
  }

  return 0;
}
