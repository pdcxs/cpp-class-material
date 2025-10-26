// https://www.geogebra.org/m/ExvvrBbR

#include <iostream>
#include <sstream>

using namespace std;

struct Node {
  int id;
  Node *next;
};

class JosephusRing {
  Node *cur;
  Node *prev;
  int stepSize;

public:
  JosephusRing(int n, int k) {
    if (n == 1) {
      cur = new Node{1, nullptr};
      cur->next = cur;
      prev = cur;
      stepSize = k;
      return;
    }
    stepSize = k;
    cur = new Node{1, nullptr};
    Node *next = cur;
    for (int i = 2; i <= n; i++) {
      if (i == n) {
        // last one
        Node *last = new Node{n, cur};
        next->next = last;
        prev = last;
        break;
      }
      Node *nt = new Node{i, nullptr};
      next->next = nt;
      next = nt;
    }
  }

  bool isLast() { return cur->next == cur; }

  int step() {
    if (isLast()) {
      return cur->id;
    }
    for (int i = 1; i < stepSize; i++) {
      prev = cur;
      cur = cur->next;
    }
    int r = cur->id;
    prev->next = cur->next;
    delete cur;
    cur = prev->next;
    return r;
  }

  int current() { return cur->id; }

  ~JosephusRing() {
    while (true) {
      Node *n = cur->next;
      if (n == cur) {
        delete cur;
        break;
      }
      delete cur;
      cur = n;
    }
  }
};

int main() {
  int n, k;

  cout << "Please input ring size and step size:" << endl;

  while (true) {
    cout << ">>> ";

    string line;
    getline(cin, line);
    if (line.empty())
      break;

    istringstream is(line);
    is >> n >> k;

    JosephusRing ring{n, k};
    while (true) {
      if (ring.isLast()) {
        cout << ring.current() << endl;
        break;
      }
      cout << ring.step();
      cout << ", ";
    }
  }
  return 0;
}
