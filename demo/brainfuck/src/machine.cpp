#include "machine.h"
#include <fmt/core.h>

bf::Machine::Machine(const std::string &code, int memorySize) : code(code)
{
  memory = new unsigned char[memorySize]();
  this->memorySize = memorySize;
}

bf::Machine::~Machine() { delete[] memory; }

int bf::Machine::run()
{
  while (pos < code.length())
  {
    switch (code[pos])
    {
    case '>':
      pointer++;
      if (checkPointer())
      {
        return EXIT_FAILURE;
      }
      break;

    case '<':
      pointer--;
      if (checkPointer())
      {
        return EXIT_FAILURE;
      }
      break;

    case '+':
      memory[pointer]++;
      break;

    case '-':
      memory[pointer]--;
      break;

    case '.':
      fmt::print("{:c}", memory[pointer]);
      break;

    case ',':
      memory[pointer] = std::getchar();
      break;

    case '[':
      if (memory[pointer] == 0)
        pos = getRightBracket();
      break;

    case ']':
      if (memory[pointer] != 0)
        pos = getLeftBracket();
      break;
    }
    pos++;
  }
  return 0;
}

bool bf::Machine::checkPointer()
{
  if (pointer < 0 || pointer >= memorySize)
  {
    fmt::print(
        stderr,
        "\nPointer value {} is out of range [0, {}).\n",
        pointer, memorySize);
    return true;
  }
  return false;
}

int bf::Machine::getLeftBracket()
{
  int p = pos;
  int depth = 1;
  while (depth > 0)
  {
    p--;
    if (code[p] == ']')
      depth++;
    if (code[p] == '[')
      depth--;
  }
  return p;
}

int bf::Machine::getRightBracket()
{
  int p = pos;
  int depth = 1;
  while (depth > 0)
  {
    p++;
    if (code[p] == '[')
      depth++;
    if (code[p] == ']')
      depth--;
  }
  return p;
}
