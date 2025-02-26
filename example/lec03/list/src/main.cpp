#include <iostream>

struct Node {
  int data;
  Node *next;
};

Node *make_list() { return nullptr; }

Node *prepend(Node *list, const int element) {
  Node *head = new Node();
  head->data = element;
  head->next = list;
  return head;
}

void printList(const Node *list) {
  std::cout << "[";
  const Node *head = list;
  while (head != nullptr) {
    std::cout << head->data;
    if (head->next != nullptr) {
      std::cout << ", ";
    }
    head = head->next;
  }
  std::cout << "]";
}

Node *insert(Node *list, int element, size_t index) {
  if (list == nullptr) {
    // empty list
    if (index == 0) {
      Node *newNode = new Node();
      newNode->data = element;
      newNode->next = nullptr;
      return newNode;
    }
    return list; // Fail
  }

  Node *prev = nullptr;
  Node *next = list;
  while (index > 0) {
    if (next == nullptr)
      return list; // Fail
    prev = next;
    next = next->next;
    --index;
  }
  Node *newNode = new Node();
  newNode->data = element;
  newNode->next = next;
  if (prev == nullptr) {
    return newNode;
  }
  prev->next = newNode;
  return list;
}

void freeList(Node *list) {
  while (list != nullptr) {
    Node *next = list->next;
    delete list;
    list = next;
  }
}

int main(int argc, char **argv) {
  Node *list = make_list();
  list = prepend(list, 1);
  list = prepend(list, 2);
  list = prepend(list, 3);
  printList(list);
  std::cout << std::endl;

  list = insert(list, 0, 0);
  list = insert(list, 10, 4);
  list = insert(list, -1, 1);
  printList(list);
  std::cout << std::endl;

  freeList(list);
  return 0;
}
