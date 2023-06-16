#include <iostream>
#include <string>
using namespace std;

/*
类模板对象做函数参数

学习目标：
类模板实例化出的对象，向函数传参的方式

共有三种传入方式：
1、指定传入的类型——直接线性对象的数据类型。实际开发中主要是用方式一
void printPerson1(Person<string, int> &p)；

2、参数模板化——将对象中的参数变为模板进行传递，将类模板中的参数再变成模板。
将传入的类型<>内的参数再次模板化
template <class T1, class T2>  // 函数模板搭配类模板
void printPerson2(Person<T1, T2> &p)  //此处用到了类型的自动推导

3、整个类模板化——将这个对象类型模板化进行传递
template <class T>  // 函数模板搭配类模板
void printPerson3(T &p)  // 自动推导出是Person数据类型
*/

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        m_Name = name;
        m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

// 1、指定传入的类型
void printPerson1(Person<string, int> &p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int> p("悟空", 100);
    printPerson1(p);
}

// 2、参数模板化
template <class T1, class T2>        // 函数模板搭配类模板
void printPerson2(Person<T1, T2> &p) // 此处用到了类型的自动推导
{
    p.showPerson();

    // 查看编译器推导的数据类型
    cout << "T1的类型为：" << typeid(T1).name() << endl; // 不同编译器给的结果是不一样的，但都是string的名字
    cout << "T2的类型为：" << typeid(T2).name() << endl; // 不同编译器给的结果是不一样的，但都是int的名字
}

void test02()
{
    Person<string, int> p("八戒", 90);
    printPerson2(p);
}

// 3、整个类模板化
template <class T>      // 函数模板搭配类模板
void printPerson3(T &p) // 自动推导出是Person数据类型
{
    p.showPerson();
    cout << "T的类型为：" << typeid(T).name() << endl; // 不同编译器给的结果是不一样的，但都是Person的名字
}

void test03()
{
    Person<string, int> p("唐僧", 30);
    printPerson3(p);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}