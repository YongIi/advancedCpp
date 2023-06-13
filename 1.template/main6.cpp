#include <iostream>
#include <string>
using namespace std;

/*
因为普通函数和函数模板可以发生函数重载
故要确定：普通函数与函数模板的调用规则

调用规则如下：
1、函数重载时，如果函数模板和普通函数都可以调用，优先调用普通函数
2、当想使用函数模板时，可以通过空模板参数列表<>来强制调用函数模板，<>内不用写参数
3、函数模板也可以发生重载
4、如果函数模板可以产生更好的匹配，优先调用函数模板

Note：
既然提供了函数模板，最好就不要提供普通函数了，否则容易出现二义性。以上内容只是要知道出现这种情况时的调用规则
*/

void myPrint(int a, int b)
{
    cout << "调用普通函数" << endl;
}

template <class T>
void myPrint(T a, T b)
{
    cout << "调用函数模板1" << endl;
}

template <class T>
void myPrint(T a, T b, T c)
{
    cout << "调用重载的函数模板2" << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    // Note：如果普通函数只有声明，没有实现，即使有函数模板可以调用，它也会调用普通函数，并报错（没有实现）
    myPrint(a, b);

    // 通过空模板参数列表，强制调用函数模板
    myPrint<>(a, b);

    // 调用重载的函数模板
    myPrint<>(a, b, 100);

    // 如果函数模板产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    // 调用普通函数会发生隐式类型转换为int（编译器会认为麻烦），调用函数模板则会自动推导出char类型
    myPrint(c1, c2); // 优先调用函数模板
}

int main()
{
    test01();
    return 0;
}