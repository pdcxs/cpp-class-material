#include <iostream>
#include "cons.h"

using namespace conslist;

int main()
{
    // test: [1, 2]
    auto list = cons(make_atom(1),
                     cons(make_atom(2),
                          make_atom(nullptr)));
    print_cons(list);
    std::cout << '\n'
              << length(list) << std::endl;

    // test: [(true . false), ["hello", "world"], 1.23]
    list =
        cons(
            cons(
                make_atom(true),
                make_atom(false)),
            cons(
                cons(
                    make_atom("hello"),
                    cons(
                        make_atom("world"),
                        nullptr)),
                cons(
                    make_atom(1.23),
                    nullptr)));
    print_cons(list);
    std::cout << '\n'
              << length(list) << std::endl;
    
    // test: take second element
    list = (car(cdr(list)));
    print_cons(list);
    std::cout << '\n'
              << length(list) << std::endl;
    return 0;
}
