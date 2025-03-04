#ifndef __CONS_LIST_H__
#define __CONS_LIST_H__

#include <iostream>
#include <memory>
#include <variant>

namespace conslist
{
    class ConsNode
    {
    public:
        using Atom = std::variant<int, double, std::string, bool, std::nullptr_t>;
        using Pair = std::pair<std::shared_ptr<ConsNode>, std::shared_ptr<ConsNode>>;

        // 原子构造函数，不应该直接使用构造函数创建 atom
        // 而应该使用 make_atom 函数
        explicit ConsNode(const Atom &val);

        // pair构造函数，不应该直接使用构造函数创建 cons
        // 而应该使用 cons 函数
        ConsNode(std::shared_ptr<ConsNode> car, std::shared_ptr<ConsNode> cdr);

        bool isAtom() const;
        Atom getAtom() const;
        Pair getPair() const;

    private:
        std::variant<Atom, Pair> content;
        bool is_atomic;
    };

    // cons list 长度
    size_t length(const std::shared_ptr<ConsNode> &);

    // 打印 cons, 链表会被特殊考虑
    void print_cons(const std::shared_ptr<ConsNode> &);

    // 通用化 cons 构造方法
    std::shared_ptr<ConsNode> cons(std::shared_ptr<ConsNode>,
                                   std::shared_ptr<ConsNode>);
    
    // cons 的第一个元素
    std::shared_ptr<ConsNode> car(std::shared_ptr<ConsNode>);

    // cons 的第二个元素
    std::shared_ptr<ConsNode> cdr(std::shared_ptr<ConsNode>);

    // 是否为 nil
    bool is_nil(const std::shared_ptr<ConsNode>&);

    // 是否为 list
    bool is_list(const std::shared_ptr<ConsNode>&);

    // 原子节点构造模板
    template <typename AtomType>
    inline std::shared_ptr<ConsNode> make_atom(AtomType val)
    {
        return std::make_shared<ConsNode>(val);
    }

    // 特化处理nullptr
    inline std::shared_ptr<ConsNode> make_atom(std::nullptr_t)
    {
        return std::make_shared<ConsNode>(nullptr);
    }
}

#endif