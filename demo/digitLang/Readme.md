# 简明电路描述语言指南

## 基本概念

- **电线**：用**小写字母**命名（如`x`, `y`），每条电线能传输一个**16位数字信号**（取值范围 0-65535）
- **信号来源**：
  - 🎛️ 逻辑门（AND/OR/NOT 等）
  - 📡 其他电线传递的信号
  - 🔢 直接给定的数值
- **重要特性**：
  - 每条电线**只能有一个信号来源**
  - 一条电线可以**同时给多个设备供电**
  - 所有输入信号就绪前，逻辑门不会工作

## 逻辑门操作详解

### 基础操作符

| 表达式示例      | 说明                                 |
| ----------------- | -------------------------------------- |
| `123 -> x`      | 将数值123直接传给电线x              |
| `x -> y`        | 将电线x的信号直接传给电线y          |

### 位运算操作符

| 表达式示例      | 操作说明                             | 等效编程表达式  |
| ----------------- | -------------------------------------- | ---------------- |
| `x AND y -> z`  | 对x和y信号执行按位与操作            | z = x & y      |
| `x OR y -> z`   | 对x和y信号执行按位或操作            | z = x \| y     |
| `NOT x -> y`    | 对x信号执行按位取反（16位）         | y = ~x & 0xFFFF |

### 位移操作符

| 表达式示例      | 操作说明                             | 等效编程表达式  |
|-----------------|--------------------------------------|----------------|
| `x LSHIFT 2 -> y` | 将x信号左移2位                      | y = (x << 2)   |
| `x RSHIFT 3 -> y` | 将x信号右移3位                      | y = (x >> 3)   |

## 实战案例解析

### 案例1: 123 -> x

▸ 电线x直接获得123的信号

### 案例2: x AND y -> z

▸ 当x和y都有信号时，执行x&y后传给z

▸ 若x=3(0011), y=5(0101)，则z=1(0001)

### 案例3: p LSHIFT 2 -> q

▸ 将p的信号左移2位（相当于乘以4）

▸ 若p=5，则q=20

### 案例4: NOT e -> f

▸ 对e的信号按位取反（0变1，1变0）

▸ 若e=0(0000)，则f=65535(1111 1111 1111 1111)

## 问题挑战

1. 给定一个电路描述文件（input.txt），其中包含各种逻辑门和连线的定义，请确定最终**电线a**传递的信号值。
2. 将问题1的电线a的值赋值给电线b，重新计算电线a的值。

💡 提示：这个问题改编自[Advent of Code 2015 Day 7](https://adventofcode.com/2015/day/7)，可以通过构建信号传播系统来解决，需要注意处理信号依赖顺序。


# Concise Guide to Circuit Description Language

## Basic Concepts

- **Wires**: Named using **lowercase letters** (e.g., `x`, `y`). Each wire can carry a **16-bit digital signal** (value range: 0–65535).
- **Signal Sources**:
  - 🎛️ Logic gates (AND/OR/NOT, etc.)
  - 📡 Signals transmitted from other wires
  - 🔢 Directly assigned numerical values
- **Key Features**:
  - Each wire **can have only one signal source**
  - One wire **can supply power to multiple devices simultaneously**
  - Logic gates do not operate until all input signals are ready

## Logic Gate Operations Explained

### Basic Operators

| Expression Example | Description                                  |
| ------------------ | -------------------------------------------- |
| `123 -> x`         | Directly assigns the value 123 to wire x     |
| `x -> y`           | Directly transmits the signal from wire x to wire y |

### Bitwise Operators

| Expression Example | Operation Description                        | Equivalent Programming Expression |
| ------------------ | -------------------------------------------- | --------------------------------- |
| `x AND y -> z`     | Performs a bitwise AND operation on signals x and y | z = x & y                         |
| `x OR y -> z`      | Performs a bitwise OR operation on signals x and y  | z = x \| y                        |
| `NOT x -> y`       | Performs a bitwise NOT operation on signal x (16-bit) | y = ~x & 0xFFFF                   |

### Shift Operators

| Expression Example | Operation Description                        | Equivalent Programming Expression |
|-------------------|---------------------------------------------|-----------------------------------|
| `x LSHIFT 2 -> y` | Shifts the signal from x left by 2 bits     | y = (x << 2) & 0xFFFF             |
| `x RSHIFT 3 -> y` | Shifts the signal from x right by 3 bits    | y = (x >> 3)                      |

## Practical Case Studies

### Case 1: 123 -> x

▸ Wire x directly receives the signal 123.

### Case 2: x AND y -> z

▸ When both x and y have signals, performs x & y and transmits the result to z.

▸ If x=3 (0011₂), y=5 (0101₂), then z=1 (0001₂).

### Case 3: p LSHIFT 2 -> q

▸ Shifts the signal from p left by 2 bits (equivalent to multiplying by 4).

▸ If p=5, then q=20.

### Case 4: NOT e -> f

▸ Performs a bitwise NOT on the signal from e (0 becomes 1, 1 becomes 0).

▸ If e=0 (0000 0000 0000 0000₂), then f=65535 (1111 1111 1111 1111₂).

## Challenge Problems

1. Given a circuit description file (`input.txt`) containing definitions of various logic gates and connections, determine the final signal value transmitted by **wire a**.
2. Assign the value of wire a from Problem 1 to wire b, then recalculate the value of wire a.

💡 Hint: This problem is adapted from [Advent of Code 2015 Day 7](https://adventofcode.com/2015/day/7). It can be solved by building a signal propagation system, paying attention to the order of signal dependencies.
