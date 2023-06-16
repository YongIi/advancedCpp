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