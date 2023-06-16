#pragma once // 防止头文件重复包含
#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age); // 类模板中，这个成员函数/构造函数一开始是不会创建的

    void showPerson();

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