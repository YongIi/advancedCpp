#include <iostream>
#include <string>
using namespace std;

/*
普通函数与函数模板区别：
1、普通函数调用时可以发生自动类型转换（隐式类型转换）
2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
3、如果利用显式指定T的类型，可以发生隐式类型转化

总结：建议使用显式指定类型的方式，调用函数模板，因为可以自己确定通用类型T
*/

// 普通函数
int myAdd01(int a, int b)
{
    return a + b;
}

// 函数模板
template <class T>
T myAdd02(T a, T b)
{
    return a + b;
}

void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c'; // ASCII：a - 97   b - 98   c - 99
    cout << myAdd01(a, b) << endl;
    cout << myAdd01(a, c) << endl; // 将'c'隐式地转成了整型

    // 自动类型推导，不会发生隐式类型转换
    cout << myAdd02(a, b) << endl;
    // cout << myAdd02(a, c) << endl;  // 无法推导统一的数据类型T

    // 显式指定类型，可以发生隐式类型转换
    cout << myAdd02<int>(a, c) << endl; // 显式指定T的类型后，可以发生类型转换
}

int main()
{
    test01();
    return 0;
}