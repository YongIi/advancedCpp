#include <iostream>
#include <string>
using namespace std;

#include "MyArray.hpp"

/*
类模板案例

案例描述：实现一个通用的数组类，要求如下：
-可以对内置数据类型以及自定义数据类型的数据进行存储
-将数组中的数据存储到堆区
-构造函数中可以传入数组的容量
-提供对应的拷贝构造函数以及operator=防止浅拷贝问题
-提供尾插法和尾删法对数组中的数据进行增加和删除
-可以通过下标的方式访问数组中的元素
-可以获取数组中当前元素个数和数组的容量

在类模板中维护的数组，其实就是在堆区开辟的地址

*/

void printIntArray(MyArray<int> &arr) // 参数列表中不能加const，因为常对象只能调用常(成员)函数
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " "; // 测试operator[]重载
    }
    cout << endl;
}

void test01()
{
    MyArray<int> arr1(5); // 测试拷贝和析构函数
    // MyArray<int> arr2(arr1); // 测试拷贝构造
    // MyArray<int> arr3(100);
    // arr3 = arr1;  // 测试重载operator=

    // 尾插法插入数据
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }

    cout << "arr1的打印输出为：" << endl;
    printIntArray(arr1);
    cout << "arr1的容量为：" << arr1.getCapacity() << endl;
    cout << "arr1的大小为：" << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2的打印输出为" << endl;
    printIntArray(arr2);
    // 尾删数据
    arr2.Pop_Back();
    cout << "arr2尾删后：" << endl;
    printIntArray(arr2);
    cout << "arr2的容量为：" << arr2.getCapacity() << endl;
    cout << "arr2的大小为：" << arr2.getSize() << endl;
}

// 测试自定义数据类型

class Person
{
public:
    Person() {}                  // 无参构造，方便new的时候不提供参数也能在堆区开辟Person类型的数组内存
    Person(string name, int age) // 有参构造，提供有参构造后，编译器不再提供默认构造，故需要在上行补充无参构造
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "姓名：" << arr[i].m_Name << "\t"
             << "年龄：" << arr[i].m_Age << endl; // 测试operator[]重载
    }
}

void test02()
{
    MyArray<Person> arr(10); // 容量为10
    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 25);
    Person p5("安琪拉", 17);

    // 尾插法将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    // 打印数组
    printPersonArray(arr);
    // 打印容量和大小
    cout << "arr的容量为：" << arr.getCapacity() << endl;
    cout << "arr的大小为：" << arr.getSize() << endl;

    cout << "--------额外测试--------" << endl;
    MyArray<Person> arr2(arr);
    // 打印数组
    printPersonArray(arr2);
    arr2.Pop_Back();
    MyArray<Person> arr3(4);
    arr3 = arr2;
    printPersonArray(arr3);
    cout << "arr3的容量为：" << arr3.getCapacity() << endl;
    cout << "arr3的大小为：" << arr3.getSize() << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}