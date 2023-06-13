#include <iostream>
#include <string>
using namespace std;

/*
模板的局限性

模板的通用性并不是万能的

eg1:
template<class T>
void f(T a, T b)
{
    a = b;
}
以上代码中的赋值操作，如果传入的a和b是一个数组，就无法实现了。数组间不能赋值，理由如下：
在C++中，数组间是不能直接赋值的。这是因为数组名代表数组首元素的地址，而数组在内存中是连续存储的，
所以数组名本质上是一个常量指针，不能被赋值。如果需要将一个数组的值复制到另一个数组中，
可以使用循环遍历数组，并逐个赋值。

eg2：
template<class T>
void f(T a, T b)
{
    if(a > b)
    {

    }
}
在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行，无法比较两个自定义数据类型的大小

因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板？？？？
解决方法一：
在自定义类中提供函数的重载（太复杂，不建议采用）
解决方法二：
对于自定义的数据类型，对该数据类型的模板函数提供一个重载的版本，让自定义的数据类型走重载的版本
它的本质是：当普通函数和模板函数发生重载时，优先调用普通函数

总结：
1、利用重载具体化的模板，可以解决自定义类型的通用化
2、学习模板并不是为了写模板，而是在STL能够运用系统提供的模板。即要会使用别人提供的模板

*/



class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 姓名
    string m_Name;
    // 年龄
    int m_Age;
};

// 对比两个数据是否相等的函数
template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    return false;
}

// 利用具体化自定义类型的重载版本，该具体化的版本会优先调用。本质是重载时，优先调用普通函数
// template<> bool myCompare(Person &a, Person &b)  // 指明是模板函数的重载，去掉template<>也行，如下：
bool myCompare(Person &a, Person &b)
{
    if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
    {
        return true;
    }
    return false;
}

void test01()
{
    int a = 10;
    int b = 20;

    bool ret = myCompare(a, b);

    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
}

void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool ret = myCompare(p1, p2);

    if (ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}