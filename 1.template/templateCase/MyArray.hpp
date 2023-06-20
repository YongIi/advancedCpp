// 自己的通用的数组类

#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    // 有参构造，参数：容量
    MyArray(int capacity)
    {
        // cout << "MyArray有参构造调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity]; // 开辟数组时用[容量]
    }

    // 尾插法新增数据
    void Push_Back(const T &val)
    {
        // 判断容量释放等于大小，如果是提示容量已满
        if (this->m_Capacity == this->m_Size)
        {
            cout << "容量已满，无法插入新值" << endl;
            return;
        }
        this->pAddress[this->m_Size] = val; // 在数组的末尾插入数据
        this->m_Size++;                     // 更新数组大小
    }

    // 尾删法删除末尾数据
    void Pop_Back()
    {
        // 判断数组是否已经为空，如果是就空操作
        if (this->m_Size == 0)
        {
            return;
        }

        // 让用户访问不到最后一个元素即可，是逻辑尾删，不用真正删除数据
        this->m_Size--;
    }

    // 通过下标方式访问数组中的元素——重载operator[]
    T &operator[](int index) // 为了让对象arr[10]不仅可以访问，还可以作为左值传值，eg:arr[10] = 5，需要返回引用
    {
        return this->pAddress[index];
    }

    // 返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    // 返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    // 析构函数
    ~MyArray()
    {
        if (pAddress != NULL)
        {
            // cout << "MyArray析构函数调用" << endl;
            delete[] pAddress; // delete数组时要加上[]
            pAddress = NULL;
        }
    }

    // 拷贝构造，防止默认拷贝构造的浅拷贝问题
    MyArray(const MyArray &arr)
    {
        // cout << "MyArray拷贝构造调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        // 深拷贝开辟地址
        this->pAddress = new T[arr.m_Capacity];
        // 将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            // 对于MyArray和T这两个类都要重构operator=
            // 此处要求后者自定义类型的T重载operator=，它的具体实现在T的自定义类型中，例如Person类中
            // 但若自定义数据类型没在堆区开辟内存，可以采用编译器默认的赋值运算符，则不用写重载了
            // 若有在堆区开辟内存，则需要重载operator=解决浅拷贝问题，且重载operator=后不再拥有默认的赋值运算符
            this->pAddress[i] = arr.pAddress[i]; // 对于自定义类型的T，需要重构operator=，才能赋值
        }
    }

    // 重载operator=防止浅拷贝问题。对于MyArray和T这两个类都要重构operator=，此处是前者
    // 这里参数列表()中可以传入常对象，是因为它并没有调用成员函数。如果调用了成员函数则不能加const
    MyArray &operator=(const MyArray &arr) // 链式法则返回类型是MyArray &，实现 a = b = c
    {
        // cout << "MyArray的operator=调用" << endl;
        //  先判断原来堆区是否有数据，如果有先释放，防止内存泄漏
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;

            this->m_Capacity = 0; // 重新赋值前这两个参数也要清空
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        // 深拷贝开辟地址
        this->pAddress = new T[arr.m_Capacity];
        // 将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            // 对于MyArray和T这两个类都要重构operator=
            // 此处要求后者自定义类型的T重载operator=，它的具体实现在T的自定义类型中，例如Person类中
            // 但若自定义数据类型没在堆区开辟内存，可以采用编译器默认的赋值运算符，则不用写重载了
            // 若有在堆区开辟内存，则需要重载operator=解决浅拷贝问题，且重载operator=后不再拥有默认的赋值运算符
            this->pAddress[i] = arr.pAddress[i]; // 对于自定义类型的T，需要重构operator=，才能赋值
        }

        return *this;
    }

private:
    T *pAddress; // 指针指向堆区开辟的真实数组

    int m_Capacity; // 数组容量

    int m_Size; // 数组大小
};