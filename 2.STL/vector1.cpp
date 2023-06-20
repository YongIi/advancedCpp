#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector容器

功能：
vector数据结构和数组非常相似，也称为单端数组

vector和普通数组区别：
数组是静态空间，固定容量，一但确定内存就不能再扩展了
vector可以动态扩展

动态扩展：
并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

常用iterator：
v.begin()  //指向第一个元素
v.end()    //指向最后一个元素的下一个位置
v.rbegin() //指向倒数第一个元素，倒着计数
v.rend()   //指向第一个元素的前一个位置

常用接口：
push_back()
pop_back()
front()
back()
insert()

vector容器的迭代器是支持随机访问的迭代器
*/

/*
vector构造函数

功能：
创建vector容器

函数原型（vector类模板中的函数声明）
vector<T> v;               		   //无参构造，采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());        //将v[begin(), end())区间中的元素拷贝给本身。注意是[左闭又开)区间
vector(n, elem);                   //构造函数将n个elem拷贝给本身。eg:vector(10, 100)表示10个100
vector(const vector &vec);         //拷贝构造函数。
*/

void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// vector容器构造
void test01()
{
    vector<int> v1; // 默认构造，无参构造

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    PrintVector(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    PrintVector(v2);

    // 通过n个elem方式构造
    vector<int> v3(10, 100);
    PrintVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    PrintVector(v4);
}

int main()
{
    test01();
    return 0;
}