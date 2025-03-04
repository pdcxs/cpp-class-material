#include "cons.h"

namespace conslist
{
    ConsNode::ConsNode(const Atom &val) : content(val), is_atomic(true) {}

    ConsNode::ConsNode(std::shared_ptr<ConsNode> car,
                       std::shared_ptr<ConsNode> cdr)
        : content(std::make_pair(car, cdr)), is_atomic(false) {}

    bool ConsNode::isAtom() const
    {
        return is_atomic;
    }

    ConsNode::Atom ConsNode::getAtom() const
    {
        return std::get<Atom>(content);
    }

    ConsNode::Pair ConsNode::getPair() const
    {
        return std::get<Pair>(content);
    }

    std::shared_ptr<ConsNode> cons(std::shared_ptr<ConsNode> car,
                                   std::shared_ptr<ConsNode> cdr)
    {
        return std::make_shared<ConsNode>(car, cdr);
    }
    void print_cons(const std::shared_ptr<ConsNode> &node)
    {
        if (is_nil(node))
        {
            std::cout << "nil";
            return;
        }

        if (is_list(node))
        {
            std::cout << "[";
            auto cur = car(node);
            auto next = cdr(node);
            while (true)
            {
                print_cons(cur);
                if (!is_nil(next))
                {
                    std::cout << ", ";
                    cur = car(next);
                    next = cdr(next);
                }
                else
                {
                    break;
                }
            }
            std::cout << "]";
            return;
        }

        if (node->isAtom())
        {
            std::visit([](auto &&arg)
                       {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, std::nullptr_t>)
                std::cout << "nil";
            else if constexpr (std::is_same_v<T, bool>)
                std::cout << (arg ? "true" : "false");
            else if constexpr (std::is_same_v<T, std::string>)
                std::cout << '"' << arg << '"';
            else
                std::cout << arg; }, node->getAtom());
        }
        else
        {
            auto [car, cdr] = node->getPair();
            std::cout << "(";
            print_cons(car);
            std::cout << " . ";
            print_cons(cdr);
            std::cout << ")";
        }
    }

    size_t length(const std::shared_ptr<ConsNode> &node)
    {
        if (is_nil(node))
            return 0;
        return 1 + length(cdr(node));
    }

    std::shared_ptr<ConsNode> car(std::shared_ptr<ConsNode> node)
    {
        return node->getPair().first;
    }

    std::shared_ptr<ConsNode> cdr(std::shared_ptr<ConsNode> node)
    {
        return node->getPair().second;
    }

    bool is_nil(const std::shared_ptr<ConsNode> &node)
    {
        if (node == nullptr)
            return true;
        if (node->isAtom())
        {
            if (std::holds_alternative<std::nullptr_t>(node->getAtom()))
                return true;
            else
                return false;
        }
        return false;
    }

    bool is_list(const std::shared_ptr<ConsNode> &node)
    {
        if (is_nil(node))
            return true;
        if (node->isAtom())
            return false;
        return is_list(cdr(node));
    }
}