#include <iostream>
#include <string>
using namespace std;

/*
类模板中成员函数创建时机

类模板中成员函数和普通类中成员函数创建时机是有区别的：
1、普通类中的成员函数一开始就可以创建
2、类模板中的成员函数在调用时才创建。只要这个成员函数不被调用，它是不会被创建的，运行也不会报错
*/

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show" << endl;
    }
};

template <class T>
class Myclass
{
public:
    // 类模板中的成员函数
    void func1() // 只要这个成员函数不被调用，它是不会被创建的。故运行不会报错
    {
        obj.showPerson1();
    }
    void func2() // 只要这个成员函数不被调用，它是不会被创建的。故运行不会报错
    {
        obj.showPerson2();
    }

    T obj;
};

void test01()
{
    Myclass<Person1> p;
    p.func1();
    // p.func2();  // 报错，p没有Person2的成员函数
}

int main()
{
    test01();
    return 0;
}