#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using Stone = unsigned long long;
using Count = size_t;

vector<Stone> blink(Stone stone) {
  if (stone == 0) {
    return {1};
  }
  string s = to_string(stone);
  int len = s.length();

  if (len % 2 == 0) {
    int p = len / 2;
    auto s1 = s.substr(0, p);
    auto s2 = s.substr(p, len);

    Stone n1 = atoll(s1.c_str());
    Stone n2 = atoll(s2.c_str());
    return {n1, n2};
  }

  return {stone * 2024};
}

vector<Stone> transform(const vector<Stone> &stones) {
  vector<Stone> results;
  for (auto s : stones) {
    for (auto r : blink(s)) {
      results.push_back(r);
    }
  }
  return results;
}

using Record = unordered_map<Stone, Count>;

Record transform(const Record &record) {
  Record result;
  for (const auto &[stone, count] : record) {
    for (Stone s : blink(stone)) {
      if (result.find(s) == result.end()) {
        result[s] = count;
      } else {
        result[s] += count;
      }
    }
  }
  return result;
}

int main() {
  vector<Stone> init{3028, 78, 973951, 5146801, 5, 0, 23533, 857};
  vector<Stone> r1 = init;
  for (int i = 0; i < 25; i++) {
    r1 = transform(r1);
  }
  cout << "Method 1, question 1: ";
  cout << r1.size() << endl;

  Record record;
  for (auto s : init) {
    record[s] = 1;
  }
  auto r2 = record;
  for (int i = 0; i < 25; i++) {
    r2 = transform(r2);
  }
  Count sum = 0;
  for (auto s : r2) {
    sum += s.second;
  }
  cout << "Method 2, question 1: ";
  cout << sum << endl;

  r2 = record;
  for (int i = 0; i < 75; i++) {
    r2 = transform(r2);
  }
  sum = 0;
  for (auto s : r2) {
    sum += s.second;
  }
  cout << "Method 2, question 2: ";
  cout << sum << endl;
  return 0;
}
