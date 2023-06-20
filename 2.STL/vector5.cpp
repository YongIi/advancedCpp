#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector数据存取

函数原型（vector类模板中的函数声明）
at(int idx); // 返回索引idx所指的数据
operator[];  // 返回索引idx所指的数据
front();     // 返回容器中第一个数据元素
back();      // 返回容器中最后一个数据元素

除了用迭代器获取vector容器中的元素，也可以用[]和at()

*/

void test01()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    // 不再用迭代器iterator访问，而是通过at方式访问
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 通过[]方式访问
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    // 获取第一个元素
    cout << "第一个元素为：" << v1.front() << endl;

    // 获取最后一个元素
    cout << "最后一个元素为：" << v1.back() << endl;
}

int main()
{
    test01();
    return 0;
}