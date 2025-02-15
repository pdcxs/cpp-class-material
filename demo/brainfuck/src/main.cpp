#include "machine.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: PROGRAM_NAME file\n";
    std::cerr << "Please provide a file name." << std::endl;
    return EXIT_FAILURE;
  }

  char *file = argv[1];
  std::ifstream ifstrm(file);

  if (!ifstrm.is_open()) {
    std::cerr << "Cannot open file: " << file << std::endl;
    return EXIT_FAILURE;
  }

  std::stringstream ss;

  ss << ifstrm.rdbuf();

  bf::Machine machine(ss.str());

  return machine.run();
}
