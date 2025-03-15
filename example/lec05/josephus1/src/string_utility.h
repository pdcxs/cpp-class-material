#ifndef __STRING_UTILITY_H__
#define __STRING_UTILITY_H__

#include <vector>
#include <string>
#include <optional>

// seperate a string into words
std::vector<std::string> words(const std::string &s);

// convert a string to double
// support following formats:
// 123, 1.1, 0xfa, 0xFF, 1e-3
std::optional<double> toDouble(const std::string &s);

// convert a string to int
// only supports base-10 number
std::optional<int> toInt(const std::string &s);

// check whether a string is blank
bool isBlack(const std::string &s);

#endif