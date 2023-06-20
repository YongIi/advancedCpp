#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <algorithm> // 想利用STL提供的算法，需要包含算法的头文件algorithm

/*
算法要通过迭代器才能访问容器中的元素，迭代器可以理解为指针
容器看作是STL中给的类，迭代器是指向容器元素的指针
容器看作是管理变量数组的类，迭代器是该类下的一种指向元素的指针
算法独立于容器，算法通过容器提供的迭代器来实现功能

vector存放内置数据类型

容器：vector
算法：for_each
迭代器：vector<int>::iterator
*/

/*
回调函数

传参时可以传入函数名，在实现时可以用调用该函数名(参数)
eg:test1.cpp
*/

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建一个vector容器，数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 通过迭代器iterator访问容器vector中的数据
    // v.begin() 起始迭代器，指向容器中第一个元素
    // v.end()  结束迭代器，指向容器中最后一个元素的下一个位置
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

    // 第一种遍历方式
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }

    // 第二种遍历方式，将以上多行代码写成一行
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 第三种遍历方式，利用STL提供的算法，此时需要包含算法的头文件algorithm
    // 算法独立于容器，算法通过容器提供的迭代器来实现功能
    for_each(v.begin(), v.end(), myPrint); // 回调函数，用法见test1.cpp
}

int main()
{
    test01();
    return 0;
}