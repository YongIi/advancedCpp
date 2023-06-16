#include <iostream>
#include <string>
using namespace std;

/*
类模板
函数模板是将函数内的数据类型抽象出来，用通用类型表示
类模板是将类中的数据类型抽象出来，用通用类型表示

作用：
建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
在确定对象的时候再去确定成员的具体类型

语法：在temple后面紧跟一个类
template<typename T>  // typename一般写成class，T表示通用数据类型，可以替换为其他大写字母
类

*/

// 类模板

template <class NameType, class AgeType>
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

void test01()
{
    Person<string, int> p1("悟空", 999); // 将类型以参数的形式传入模板的参数列表<>，实参传入()
    p1.showPerson();
}

int main()
{
    test01();
    return 0;
}