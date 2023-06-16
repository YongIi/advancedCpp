#include <iostream>
#include <string>
using namespace std;

/*
类模板与函数模板的区别
1、类模板没有自动类型推导的使用方式。Note：新版C++已经支持自动类型推导
2、类模板在模板参数列表中可以有默认参数（仅类模板中有），Note：据说新版C++也支持给函数模板提供默认参数了
eg: template <class NameType, class AgeType = int>
此时，使用这个类时，<>内可以省略相应的默认参数，直接采用Person<string> p；


*/

template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        m_Name = name;
        m_Age = age;
    }

    void showPerson()
    {
        cout << "name: " << m_Name << " age: " << m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

// 1、类模板没有自动类型推导的使用方式。Note：新版C++已经支持自动类型推导
void test01()
{
    Person p("悟空", 1000); // 老版C++并不支持自动类型推导，会直接报错
    p.showPerson();

    Person<string, int> p1("悟空", 1000);
    p1.showPerson();
}

// 2、类模板在模板参数列表中可以有默认参数
void test02()
{
    Person<string> p("猪八戒", 999); // 当模板中对AgeType给了默认参数int，则可以省略第二个类型参数
    p.showPerson();
}

int main()
{
    test01();
    test02();
    return 0;
}