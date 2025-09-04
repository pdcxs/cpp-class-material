# Brainfuck

这是一门最小的图灵完备语言，详情参考： [最小图灵完备语言](https://www.cnblogs.com/boring09/p/4865640.html)
该语言假设有一个数组，支持以下几种操作：

1. **>**: 数组当前指针向右移动一格
2. **<**: 数组当前指针向左移动一格
3. **+**: 数组当前指针对应的数字加一
4. **-**: 数组当前指针对应的数字减一
5. **.**: 前当前指针对应数字的ASCII码的字符输出
6. **,**: 读取一个字符，将其ASCII码保存到当前指针位置
7. **[**: 如果当前指针数字为0，则跳转到对应的]的位置。
8. **]**: 如果当前指针数字不为0，则跳转到对应的**[**的位置
9. 其他字符忽略

通过以下命令运行代码：

```bash
xmake run brainfuck fib.txt
```

提供的三个程序程序：

- hello.txt: Hello World程序
- factorial.txt: 不断打印从1开始的自然数的阶乘，真到内存溢出
- fib.txt: 不断打印斐波那契数列，真到内存溢出

# Brainfuck

This is a minimal Turing complete language. For details, refer to: [Minimal Turing Complete Language](https://en.wikipedia.org/wiki/Brainfuck).

The language assumes the existence of an array and supports the following operations:

1. **>**: Move the array pointer one step to the right.
2. **<**: Move the array pointer one step to the left.
3. **+**: Increment the value at the current pointer position.
4. **-**: Decrement the value at the current pointer position.
5. **.**: Output the character corresponding to the ASCII code of the value at the current pointer position.
6. **,**: Read a character and store its ASCII code at the current pointer position.
7. **[**: If the value at the current pointer is 0, jump to the corresponding **]** position.
8. **]**: If the value at the current pointer is not 0, jump to the corresponding **[** position.
9. Other characters are ignored.

Run the code using the following command:

```bash
xmake run brainfuck fib.txt
```

The three provided programs:

- hello.txt: A "Hello World" program.
- factorial.txt: Continuously prints the factorial of natural numbers starting from 1 until memory overflows.
- fib.txt: Continuously prints the Fibonacci sequence until memory overflows.
