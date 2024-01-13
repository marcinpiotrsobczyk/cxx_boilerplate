
#include <cstring>
#include <exception>
#include <filesystem>
#include <iostream>

#include "glaze/json/read.hpp"
#include "glaze/json/write.hpp"

int main(int argc, const char **argv) {
  const char *filename;

  if (argc >= 2) {
    filename = argv[1];
  } else {
    filename = "example.json";
  }
  std::cout << filename << "\n";

  glz::json_t json{};
  auto ec = glz::read_file_json(json, filename, std::string{});
  if (ec) {
    throw std::runtime_error("ec");
  }

  std::string out;
  glz::write_json(json, out);

  std::cout << out << "\n";

  return 0;
}
