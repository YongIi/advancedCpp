#include <iostream>
#include <string>
using namespace std;

/*
模板的基本概念
无法就是把类型抽象出来，改为通用的T，在使用函数模板的时候用<type>指定T的类型
模板的目的是为了提高复用性，将类型参数化

C++另一种编程思想称为泛型编程，主要利用的技术就是模板
C++提供两种模板机制：函数模板和类模板

# 函数模板

作用：
建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表
即：把函数的返回类型和参数类型抽象出来，使用的时候再确定里面的类型

语法：
template<typename T>  //T是一个通用的虚拟类型
函数声明或定义
void mySwap(T &a, T &b)

解释：
template——声明创建模板
typename——表面其后面的符号是一种数据类型，可以用class代替
T——通用的数据类型，名称可以替换，通常为大写字母

两种方式使用模板：
1、自动类型推导
mySwap(a, b);
例如传入的是两个int类型，推导出int类型
2、显示指定类型
mySwap<int>(a, b);
就是多了一个尖括号<type>指定模板中的T是<type>内指定的类型


*/

// 交换两个整型的函数
void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 交换两个浮点型的函数
void swapDouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// 函数模板
template <typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    swapInt(a, b);

    // 利用函数模板交换
    mySwap(a, b); // 方式一：自动类型推导

    mySwap<int>(a, b); // 方式二：显式指定类型

    cout << "a = " << a << "\t\t"
         << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble(c, d);

    // 利用函数模板交换
    mySwap(c, d);
    mySwap<double>(c, d);

    cout << "c = " << c << "\t\t"
         << "d = " << d << endl;
}

int main()
{
    test01();
    return 0;
}