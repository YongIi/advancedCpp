#include <iostream>
#include <string>
using namespace std;

/*
类模板与友元

学习目标：
掌握类模板配合友元函数的类内和类外实现

1、全局函数类内实现——直接在类内声明友元即可，即将全局函数的声明和实现写在类内
friend void printPerson(Person<T1, T2> p) // 因为前面加了friend，所以是全局函数
    {
        cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
    }

2、全局函数类外实现——需要提前让编译器知道全局函数的存在
类内需要在函数名后加空模板参数列表<>
如果不加，则它是一个普通全局函数，与类外实现时是一个函数模板冲突，编译器认为不是同一个东西

总结：建议全局函数配合友元做类内实现，用法简单，而且编译器可以直接识别。类外实现太啰嗦了

*/

// 通过全局函数打印Person信息

// 提前让编译器知道Person类的存在，不然全局函数printPerson2识别不了Person类
template <class T1, class T2>
class Person;

// 全局函数类外实现，要放在类模板实现的前面让编译器提前知道它的存在
template <class T1, class T2>
void printPerson2(Person<T1, T2> p) // 本质是一个函数模板
{
    cout << "类外实现——name: " << p.m_Name << " age: " << p.m_Age << endl;
}

template <class T1, class T2>
class Person
{
    // 1、全局函数类内实现
    friend void printPerson(Person<T1, T2> p) // 因为前面加了friend，所以是全局函数
    {
        cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
    }

    // 2、全局函数类外实现
    // 类内需要在函数名后加空模板参数列表<>
    // 如果不加，则它是一个普通全局函数，与类外实现时是一个函数模板冲突，编译器认为不是同一个东西
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p); // 因为前面加了friend，所以是全局函数

public:
    Person(T1 name, T2 age)
    {
        m_Name = name;
        m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 1、全局函数在类内实现
void test01()
{
    Person<string, int> p("悟空", 1000);
    printPerson(p);
}

// 2、全局函数在类外实现
void test02()
{
    Person<string, int> p("Tom", 20);
    printPerson2(p);
}

int main()
{
    test01();
    test02();
    return 0;
}