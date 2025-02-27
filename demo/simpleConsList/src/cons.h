#ifndef __SIMPLE_CONS_LIST__
#define __SIMPLE_CONS_LIST__

#include <functional>
#include <iostream>
#include <memory>

namespace conslist {
class list;

using object = int;
using listPointer = std::shared_ptr<const list>;

void print(const list &);
void print(const listPointer &);

listPointer cons(object head, listPointer tail);
object car(listPointer);
listPointer cdr(listPointer);

int length(const listPointer);
listPointer map(const listPointer, std::function<int(int)>);

class list {
public:
  list(object head, listPointer tail) : head_(head), tail_(std::move(tail)) {}

  object head() const { return head_; }

  listPointer tail() const { return tail_; }

private:
  object head_;
  listPointer tail_;
};

} // namespace conslist

#endif
