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
  int count;

public:
  JosephusRing(int n, int k) {
    stepSize = k;
    count = n;
    if (n == 1) {
      cur = new Node{1, nullptr};
      cur->next = cur;
      prev = cur;
      return;
    }
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

  int step() {
    if (count == 1) {
      int r = cur->id;
      delete cur;
      count--;
      return r;
    }
    for (int i = 1; i < stepSize; i++) {
      prev = cur;
      cur = cur->next;
    }
    int r = cur->id;
    prev->next = cur->next;
    delete cur;
    count--;
    cur = prev->next;
    return r;
  }

  int current() { return cur->id; }

  int size() { return count; }

  ~JosephusRing() {
    while (count > 0) {
      Node *tmp = cur->next;
      // cout << "Delete node " << cur->id << "\n";
      delete cur;
      cur = cur->next;
      count--;
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
    while (ring.size() > 0) {
      cout << ring.step();
      if (ring.size() > 0)
        cout << ", ";
    }
    cout << "\n";
  }
  return 0;
}
