#include <example/tools.hpp>
#include <example_header_only/tools.hpp>

#include <cli/cli.h>
#include <cli/clifilesession.h>

#include <memory>
#include <ostream>


int main() {
  example::PrintHello();
  example_header_only::PrintHello();

    auto rootMenu = std::make_unique< cli::Menu >( "cli" );
    rootMenu -> Insert(
            "hello",
            [](std::ostream& out){ out << "Hello, world\n"; },
            "Print hello world" );
    rootMenu -> Insert(
            "hello_everysession",
            [](std::ostream&){ cli::Cli::cout() << "Hello, everybody" << std::endl; },
            "Print hello everybody on all open sessions" );
    rootMenu -> Insert(
            "answer",
            [](std::ostream& out, int x){ out << "The answer is: " << x << "\n"; },
            "Print the answer to Life, the Universe and Everything " );
    rootMenu -> Insert(
            "color",
            [](std::ostream& out){ out << "Colors ON\n"; cli::SetColor(); },
            "Enable colors in the cli" );
    rootMenu -> Insert(
            "nocolor",
            [](std::ostream& out){ out << "Colors OFF\n"; cli::SetNoColor(); },
            "Disable colors in the cli" );

    auto subMenu = std::make_unique< cli::Menu >( "sub" );
    subMenu -> Insert(
            "hello",
            [](std::ostream& out){ out << "Hello, submenu world\n"; },
            "Print hello world in the submenu" );
    subMenu -> Insert(
            "demo",
            [](std::ostream& out){ out << "This is a sample!\n"; },
            "Print a demo string" );

    auto subSubMenu = std::make_unique< cli::Menu >( "subsub" );
    subSubMenu -> Insert(
        "hello",
        [](std::ostream& out){ out << "Hello, subsubmenu world\n"; },
        "Print hello world in the sub-submenu" );
    subMenu -> Insert( std::move(subSubMenu));

    rootMenu -> Insert( std::move(subMenu) );


    cli::Cli cli( std::move(rootMenu) );
    // global exit action
    cli.ExitAction( [](auto& out){ out << "Goodbye and thanks for all the fish.\n"; } );

    cli::CliFileSession input(cli);
    input.Start();


  return 0;
}
