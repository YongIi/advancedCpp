#include <iostream>
#include <string>
using namespace std;

/*
预处理与宏定义
预处理指的是在编译前对源代码进行一些处理，例如宏替换、条件编译等。不是所有编程语言都有预处理器，但是大部分编程语言都支持类似的功能。Python是一种解释型语言，没有预处理器，但是可以通过一些特殊的注释和字符串操作来实现类似的功能。

在C++中，预处理指令是大小写不敏感的，也就是说，预处理指令可以使用大写字母、小写字母或者大小写混合的形式。
例如:
#define debug
#define Debug
#define DEBUG
编译器都会将其视为相同的指令,建议你在编写代码时保持一致性和规范性，使用统一的大小写形式来编写预处理器指令，以便于代码的阅读和维护。

预处理是包含宏定义的，即宏定义是预处理的一个子概念

预处理：
不是编译器真正编译的一部分，而是在编译代码前的一个单独步骤，是编译前的预处理步骤
该步骤可以是文本替换、文本选择、嵌入内部的命令等等
预处理指令不是C++语句，所以它们不会以分号;结尾


宏定义：
本质就是预处理器做了一个文本替换的工作

特点：
所有预处理器命令都是以#开头，要注意区分预处理语句和实际的代码语句

#常用的预处理指令
#include            包含一个源代码文件
#define, #undef     定义/取消一个宏
#ifdef, #ifndef     如果之前宏(没)有被定义(不在乎宏的取值)，返回真，并开始一个条件编译块
#if, #else, #elif   定义一个条件编译块
#endif              结束一个条件编译块
#error              输出错误信息，编译会中断，通常用来识别一些编译层面的错误
#pragma             可向编译器发布特殊命令，控制编译，eg: #pragma once // 防止头文件重复包含

#include
将一个文件嵌入到另一个文件，是直接把所有内容复制粘贴过来
好处：引入头文件，进而引用另一个模块；模块优化设计、系统库、静态库
注意：配合#ifndef来防止重复引入同一个文件

#define
定义一个宏，这个宏将在编译前被替换为它所定义的文本/值，宏一直有效直到#undef
#define MAX_SIZE 10
#undef MAX_SIZE

#define的妙用
参数化的宏：像函数一样的用法
#define square(x) ((x)*(x))  //注意一定要对每个量都加上括号()，否则文本替换可能出现问题
int var = square(x)

多行宏用反斜杠\换行。注意一定要对每个量都加上括号()，否则文本替换可能出现问题
#define calc(a, b)     \
    (((a) * (a) + (b) * (b)) + \
     2 * (a) * (b))

宏的要点：
-通常命名为大写
-通常用做为静态配置参数，可以让编译好的程序有不同的行为
-宏与条件编译(#if等等)配合，可以静态调整程序模块、逻辑流程等等
-参数宏是代码替换，可能引起二进制代码的体积增大


常用用途：
1、用#ifndef防止重复引入同一个文件
eg: 在.h文件中有：
#ifndef _A_HEAD_NAME_H  // 保证在第一次没有该宏定义时，就会引用文件内容；下次再引用该文件就会跳过
#define _A_HEAD_NAME_H
//文件内容
#endif

2、对不同的编译环境/系统/硬件，进行兼容性的选择，不同的环境选择不同的编译块
eg:
#if 条件1  // 如果之前定义了条件1的宏，就执行代码块1
// 代码块1
#elsif 条件2
// 代码块2
#else
// 代码块3
#endif


3、设置debug编译块，当debug模式打开时，会新增输出/打印信息
#define DEBUG // 注释则不再输出调试信息
#ifdef DEBUG // 用于检查一个标识符是否被定义，若true则执行下面的代码块
    cout << "输出调试信息" << endl;
#endif

*/

// 不同系统兼容
#define WINDOWS 0 // 1对应选择Windows，0则关闭
#define LINUX 1

// 设置debug模型
#define DEBUG // 注释则不再输出调试信息

#define square(x) ((x) * (x))

// 注意一定要对每个量都加上括号()，否则文本替换可能出现问题
#define calc(a, b)             \
    (((a) * (a) + (b) * (b)) + \
     2 * (a) * (b))

int main()
{
#if WINDOWS
    cout << "使用Windows相关代码" << endl;
#elif LINUX
    cout << "使用Linux相关代码" << endl;
#else
    cout << "请在代码中选择执行Windows或是Linux相关的代码" << endl;
#endif

#ifdef DEBUG // 用于检查一个标识符是否被定义，若true则执行下面的代码块
    cout << "输出调试信息" << endl;
#endif

    int var = square(5);
    cout << var << endl;

    cout << calc(2, 4) << endl;

    return 0;
}