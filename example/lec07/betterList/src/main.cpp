#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

class List {
public:
  using ItemType = int;
  class Node {
  public:
    explicit Node(int value = 0) : data(value) {}

  private:
    ItemType data;
    shared_ptr<Node> next;
    friend List;
  };

  shared_ptr<Node> last() const {
    if (head == nullptr) {
      return nullptr;
    }
    auto p = head;
    while (p->next != nullptr) {
      p = p->next;
    }
    return p;
  }

  List &append(int value) {
    auto node = make_shared<Node>(value);
    return append(node);
  }

  List &append(const shared_ptr<Node> node) {
    auto lastNode = last();
    if (lastNode == nullptr) {
      head = node;
    } else {
      lastNode->next = node;
    }
    return *this;
  }

  List() {}
  List(const List &other) { head = other.copy(); }
  void operator=(const List &other) { head = other.copy(); }

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

  shared_ptr<Node> copy() const {
    if (head == nullptr)
      return nullptr;
    auto p = head;
    auto newHead = make_shared<Node>(head->data);
    auto cur = newHead;
    while (p->next != nullptr) {
      p = p->next;
      auto n = make_shared<Node>(p->data);
      cur->next = n;
      cur = n;
    }
    return newHead;
  }
};

int main() {
  List lst;
  lst.append(1).append(2).append(3);
  cout << "lst: " << lst.to_string() << endl;

  List lst2 = lst;
  lst2.append(100);
  cout << "lst: " << lst.to_string() << endl;
  cout << "lst2: " << lst2.to_string() << endl;
  return 0;
}
