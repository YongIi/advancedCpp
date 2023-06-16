#include <iostream>
#include <string>
using namespace std;

/*
类模板与继承

当类模板碰到继承时，需要注意以下几点：
1、当子类继承的父类是一个类模板时，子类在声明的时候，要制定出父类中T的类型
2、如果不指定，编译器无法给子类分配内存，因为子类又不是类模板，当不指定父类T的类型时，无法确定给多少内存
3、如果想灵活指定出父类中T的类型，子类也需变为类模板
*/

template <class T>
class Base
{
    T m;
};

// class Son : public Base  // 错误，必须要给定父类中T的类型，才能继承
class Son : public Base<int> // 此时子类中的T只能是int类型
{
};

void test01()
{
    Son s1;
}

// 如果想灵活指定出父类中T的类型，子类也需变为类模板
template <class T1, class T2>
class Son2 : public Base<T2> // T2是指定的父类中T的类型
{
public:
    Son2()
    {
        cout << "T1的类型为：" << typeid(T1).name() << endl;
        cout << "T2的类型为：" << typeid(T2).name() << endl;
    }
    T1 obj; // T1是子类中obj的类型
};

void test02()
{
    Son2<int, char> S2;
}

int main()
{
    test01();
    test02();
    return 0;
}