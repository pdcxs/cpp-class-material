#include <functional>
#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

class Node {
public:
  explicit Node(int data = 0) : data(data) {}
  int get() const { return data; }

private:
  int data;
  shared_ptr<Node> next;

  friend class List;
  friend void transform(List &lst, function<int(int)>);
};

class List {
public:
  List() {}
  shared_ptr<Node> last() const {
    auto p = head;
    if (p == nullptr)
      return p;
    while (p->next != nullptr) {
      p = p->next;
    }
    return p;
  }

  void append(shared_ptr<Node> &n) {
    auto l = last();
    if (l == nullptr) {
      head = n;
    } else {
      l->next = n;
    }
    n->next = nullptr;
  }

  string to_string() const {
    ostringstream oss;
    oss << "[";
    auto p = head;
    while (p != nullptr) {
      oss << p->data;
      if (p->next == nullptr)
        break;
      oss << ", ";
      p = p->next;
    }
    oss << "]";
    return oss.str();
  }

private:
  shared_ptr<Node> head;

  friend void transform(List &lst, function<int(int)>);
};

void transform(List &lst, function<int(int)> func) {
  if (lst.head == nullptr)
    return;
  auto p = lst.head;
  while (p != nullptr) {
    p->data = func(p->data);
    p = p->next;
  }
}

int square(int x) { return x * x; }

int main() {
  List l;
  for (int i = 0; i < 10; i++) {
    auto node = make_shared<Node>(i);
    l.append(node);
  }

  cout << l.to_string() << endl;

  transform(l, square);

  cout << l.to_string() << endl;

  return 0;
}
