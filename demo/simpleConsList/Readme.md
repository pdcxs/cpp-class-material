# simpleConsList

一种非常简陋的 [cons list](https://en.wikipedia.org/wiki/Cons) 的 `C++` 实现方式。

不支持动态类型，只支持 `int` 类型。

如果想要实现存放动态类型的效果，建议使用 `c++17` 引入的 `std::variant`。

此项目主要在于扩展一下视野，看看另一种 `list` 的实现方式。在这种实现方式下，能够很简单的实现很多数组操作，例如：

- `map`，有些地方也称为 `transform`
- `filter`
- `fold`，有些地方也称为 `reduce`

如果有兴趣，可以在此项目基础上作如下扩展：

- 引入动态类型 `std::variant`
- 实现多维链表和树
- 实现 `filter` 和 `fold` 函数
- 实现惰性链表 [`stream`](https://sarabander.github.io/sicp/html/3_002e5.xhtml#g_t3_002e5)
