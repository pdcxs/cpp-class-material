#ifndef __JOSEPHUS_RING_H__
#define __JOSEPHUS_RING_H__

#include <iostream>
#include <utility>
#include <optional>
#include <vector>

namespace josephus
{

    using Id = size_t;
    // Current and Next Id
    using Elem = std::pair<Id, Id>;
    // Prev and Current Id
    using State = std::pair<Id, Id>;
    using Ring = std::vector<Elem>;

    inline Id getPrev(const State &state);

    inline Id getCurrent(const State &state);

    inline Id getId(const Elem &node);

    inline Id getNext(const Elem &node);

    inline void setId(Ring &ring, Id node, Id id);

    inline void setNext(Ring &ring, Id node, Id next);

    inline State forward(const Ring &ring, State current);

    State step(const Ring &ring, State current, size_t stepSize);

    State kill(Ring &ring, State current);

    bool isLast(const Ring &ring, State current);

    std::optional<Ring> create(int n);

    std::vector<Id> run(Ring &ring, size_t stepSize);

    void printResult(const std::vector<Id> &result);
}
#endif