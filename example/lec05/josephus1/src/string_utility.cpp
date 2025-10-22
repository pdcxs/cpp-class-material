#include "string_utility.h"
#include <algorithm>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<string> words(const string &s) {
  vector<string> tokens;
  istringstream iss(s);
  string token;
  while (iss >> token) {
    tokens.push_back(token);
  }
  return tokens;
}

optional<double> toDouble(const string &s) {
  if (s.empty())
    return std::nullopt;
  char *end;
  double n = strtod(s.c_str(), &end);
  if (*end == '\0') {
    return n;
  }
  return nullopt;
}

optional<int> toInt(const string &s) {
  if (s.empty())
    return std::nullopt;
  char *end;

  errno = 0;
  long n = strtol(s.c_str(), &end, 10);
  if (*end != '\0') {
    return nullopt;
  }
  if (errno == ERANGE) {
    return nullopt;
  }
  if (n < INT_MIN || n > INT_MAX) {
    return nullopt;
  }

  return static_cast<int>(n);
}

bool isBlack(const string &s) {
  return all_of(s.begin(), s.end(), [](const char c) { return isblank(c); });
}
