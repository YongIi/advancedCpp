#include <iostream>
#include <string>
using namespace std;

/*
函数模板的注意事项
1、自动类型推导，必须推导出一致的数据类型T，才可以使用
2、模板必须要确定出T的数据类型，才可以使用


*/

template <typename T> // typename可以替换成class，class一般用于类模板，只是名字上的区别
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 1、自动类型推导，必须推导出一致的数据类型T，才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    double d = 1.1;
    mySwap(a, b);
    // mySwap(a, c); // 错误，推导不出一致的T类型
    // mySwap(a, d); // 错误，推导不出一致的T类型

    cout << "a = " << a << "\t\t"
         << "b = " << b << endl;
}

// 2、模板必须要确定出T的数据类型，才可以使用
template <class T>
void func()
{
    cout << "func函数调用" << endl;
}

void test02()
{
    // func();      // 错误，推导不出T的类型
    func<int>(); // 直接给出T的类型，就可以调用了
}

int main()
{
    test01();
    test02();
    return 0;
}