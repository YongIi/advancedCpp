#include<iostream>
#include<string>
using namespace std;

/*
初识STL

2.1 STL的诞生
-长久以来，软件界一致希望建立一种可重复利用的东西
-C++的面向对象和泛型编程思想，目的就是复用性的提升
-大多数情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
-为了建立数据结构额算法的一套标准，诞生了STL

2.2 STL基本概念
-STL——Standard Template Library，标准模板库
-STL从广义上分为：容器(container)、算法(algorithm)、迭代器(iterator)
-容器和算法之间通过迭代器进行无缝链接
-STL几乎所有的代码都采用了模板类或者模板函数

2.3 STL六大组件(STL的细分)
STL大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器(配接器)、空间配置器
1. 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据。
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂。
4. 仿函数：行为类似函数，可作为算法的某种策略。
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
6. 空间配置器：负责空间的配置与管理。

2.4 STL中容器、算法、迭代器
容器：置物之所也
STL容器就是将运用最广泛的一些数据结构实现出来
常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表 等
这些容器分为**序列式容器**和**关联式容器**两种:
序列式容器:强调值的排序，序列式容器中的每个元素均有固定的位置。
关联式容器:二叉树结构，各元素之间没有严格的物理上的顺序关系

算法：问题之解法也
有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
算法分为:**质变算法**和**非质变算法**。
质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

迭代器：容器和算法之间粘合剂
算法要通过迭代器才能访问容器中的元素
提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
每个容器都有自己专属的迭代器
迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为**指针**

迭代器种类：

| 种类           | 功能                                               | 支持运算                             |
| -------------- | -------------------------------------------------- | ------------------------------------|
| 输入迭代器     | 对数据的只读访问                                     | 只读，支持++、==、！=                 |
| 输出迭代器     | 对数据的只写访问                                     | 只写，支持++                          |
| 前向迭代器     | 读写操作，并能向前推进迭代器                          | 读写，支持++、==、！=                  |
| 双向迭代器     | 读写操作，并能向前和向后操作                          | 读写，支持++、--，                     |
| 随机访问迭代器 | 读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器 | 读写，支持++、--、[n]、-n、<、<=、>、>= |

常用的容器中迭代器种类为双向迭代器，和随机访问迭代器



*/



int main()
{
    return 0;
}