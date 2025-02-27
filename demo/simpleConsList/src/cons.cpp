#include "cons.h"

namespace conslist {

void print(const list &lst) {
  std::cout << "(";
  std::cout << lst.head();
  std::cout << " . ";
  conslist::print(lst.tail());
  std::cout << ")";
}

void print(const listPointer &lst) {
  if (lst)
    conslist::print(*lst);
  else
    std::cout << "NIL";
}

listPointer cons(object head, listPointer tail) {
  return std::make_shared<list>(head, std::move(tail));
}

object car(listPointer lst) { return lst->head(); }

listPointer cdr(listPointer lst) { return lst->tail(); }

int length(const listPointer lst) {
  if (lst)
    return 1 + length(lst->tail());
  else
    return 0;
}

listPointer map(const listPointer lst, std::function<int(int)> f) {
  if (lst)
    return cons(f(lst->head()), map(lst->tail(), f));
  else
    return nullptr;
}

} // namespace conslist
