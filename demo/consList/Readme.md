# simpleConsList

一种 [cons list](https://en.wikipedia.org/wiki/Cons) 的 `C++` 实现方式。

此项目主要在于扩展一下视野，看看另一种 `list` 的实现方式。在这种实现方式下，能够很简单的实现很多数组操作，例如：

- `map`，有些地方也称为 `transform`
- `filter`，有些地方也称为 `select`
- `fold`，有些地方也称为 `reduce`

如果有兴趣，可以在此项目基础上作如下扩展：

- 引入动态类型 `std::variant`
- 实现多维链表和树
- 实现 `map`、`filter` 和 `fold` 函数，参考资料：[SICP](https://sarabander.github.io/sicp/html/2_002e2.xhtml)
- 实现惰性链表 [`stream`](https://sarabander.github.io/sicp/html/3_002e5.xhtml#g_t3_002e5)

# simpleConsList

A C++ implementation of a [cons list](https://en.wikipedia.org/wiki/Cons).

The main purpose of this project is to broaden perspectives by exploring an alternative implementation of a list. With this implementation, many array operations can be easily achieved, such as:

- `map`, also known as `transform` in some contexts.
- `filter`, also known as `select` in some contexts.
- `fold`, also known as `reduce` in some contexts.

If interested, you can extend this project with the following features:

- Introduce dynamic types using `std::variant`.
- Implement multi-dimensional linked lists and trees.
- Implement the `map`, `filter`, and `fold` functions. For reference, see: [SICP](https://sarabander.github.io/sicp/html/2_002e2.xhtml).
- Implement lazy linked lists, known as [`stream`](https://sarabander.github.io/sicp/html/3_002e5.xhtml#g_t3_002e5).
