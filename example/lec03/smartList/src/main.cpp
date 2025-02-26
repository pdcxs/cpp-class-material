#include <iostream>
#include <memory>

using namespace std;

struct Node {
  int data;
  shared_ptr<Node> next;
};

shared_ptr<Node> prepend(shared_ptr<Node> &list, const int elem) {
  shared_ptr<Node> node = make_shared<Node>();
  node->data = elem;
  node->next = list;
  return node;
}

void printList(shared_ptr<const Node> list) {
  cout << "[";
  while (list != nullptr) {
    cout << list->data;
    list = list->next;
    if (list != nullptr) {
      cout << ", ";
      continue;
    }
  }
  cout << "]";
}

int main() {
  shared_ptr<Node> list = nullptr;
  list = prepend(list, 1);
  list = prepend(list, 2);
  list = prepend(list, 3);
  printList(list);

  return 0;
}
