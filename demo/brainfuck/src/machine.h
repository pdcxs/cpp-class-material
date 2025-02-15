#ifndef BRAIN_FUCK_MACHINE
#define BRAIN_FUCK_MACHINE

#include <string>

namespace bf {
class Machine {
private:
  std::string code;
  unsigned char *memory = nullptr;
  int memorySize = 0;
  int pointer = 0;
  int pos = 0;

public:
  Machine(const std::string &code, int memorySize = 256);
  int run();
  ~Machine();

private:
  bool checkPointer();
  int getLeftBracket();
  int getRightBracket();
};
} // namespace bf

#endif
