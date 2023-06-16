#include <iostream>
#include <string>
using namespace std;

/*
类模板分文件编写问题及解决

学习目标：
掌握类模板成员函数分文件编写产生的问题以及解决方式

问题：
类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到。主程序调用外部类的处理
在类模板的分文件编写中，因为类函数只有在调用时才会创建，所以会出现问题，需要将头文件改成.cpp

解决：
解决方式1：直接包含.cpp源文件。开发时基本是不会这样操作，没有把源文件交给别人看的
解决方式2：将声明.h和实现.cpp写到同一个文件中，并更改后缀名为.hpp。hpp是约定的名称，并不是强制的（主流方法）

.cpp 是实现
.h   是声明
.hpp 是将声明和实现写在同一个.hpp文件中。看到.hpp文件就知道是类模板

以下内容是分文件编写前的完整code
*/

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age); /*
    {
        m_Name = name;
        m_Age = age;
    } */

    void showPerson(); /*
    {
        cout << "name: " << m_Name << " age:" << m_Age << endl;
    } */

    T1 m_Name;
    T2 m_Age;
};

// 构造函数类外实现
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    m_Name = name;
    m_Age = age;
};

// 成员函数类外实现
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "name: " << m_Name << " age:" << m_Age << endl;
}

void test01()
{
    Person<string, int> p("悟空", 1000);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}