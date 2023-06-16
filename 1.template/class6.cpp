#include <iostream>
#include <string>
using namespace std;

/*
类模板成员函数类外实现
1、因为类外不认识T，所以类外也要有template <class T1, class T2>
2、为了指明它是类模板的类外实现，作用域后边要有<>参数列表
Person<T1, T2>::Person(T1 name, T2 age)

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