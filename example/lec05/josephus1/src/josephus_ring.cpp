#include "josephus_ring.h"
#include <iostream>

using namespace std;

namespace josephus {
inline Id getPrev(const State &state) { return state.first; }

inline Id getCurrent(const State &state) { return state.second; }

inline Id getId(const Elem &node) { return node.first; }

inline Id getNext(const Elem &node) { return node.second; }

inline void setId(Ring &ring, Id node, Id id) { ring[node].first = id; }

inline void setNext(Ring &ring, Id node, Id next) { ring[node].second = next; }

inline State forward(const Ring &ring, State current) {
  auto [prev, cur] = current;
  return {getNext(ring[prev]), getNext(ring[cur])};
}

State step(const Ring &ring, State current, size_t stepSize) {
  for (int i = 0; i < stepSize; i++) {
    current = forward(ring, current);
  }
  return current;
}

State kill(Ring &ring, State current) {
  auto [prev, cur] = current;
  Id next = getNext(ring[cur]);
  setNext(ring, prev, next);
  return {prev, next};
}

bool isLast(const Ring &ring, State current) {
  auto [_, cur] = current;
  auto n = ring[cur];
  return getNext(n) == getId(n);
}

optional<Ring> create(int n) {
  if (n < 1)
    return nullopt;

  Ring ring(n);
  for (int i = 0; i < n - 1; i++) {
    setId(ring, i, i);
    setNext(ring, i, i + 1);
  }
  setId(ring, n - 1, n - 1);
  setNext(ring, n - 1, 0);
  return ring;
}

vector<Id> run(Ring &ring, size_t stepSize) {
  State current{ring.size() - 1, 0};
  vector<Id> result;
  result.reserve(ring.size());

  while (!isLast(ring, current)) {
    current = step(ring, current, stepSize - 1);
    result.push_back(getCurrent(current));
    current = kill(ring, current);
  }
  result.push_back(getId(current));
  return result;
}

void printResult(const vector<Id> &result) {
  for (int i = 0; i < result.size() - 1; i++) {
    cout << result[i] + 1 << ", ";
  }
  cout << result[result.size() - 1] + 1 << endl;
}
} // namespace josephus
