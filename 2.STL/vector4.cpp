#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector插入和删除

函数原型（vector类模板中的函数声明）
push_back(ele);                                  // 尾部插入元素ele
pop_back();                                      // 删除最后一个元素
insert(const_iterator pos, ele);                 // 迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count, ele);      // 迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);                       // 删除迭代器指向的元素
erase(const_iterator start, const_iterator end); // 删除迭代器从start到end之间的元素，注意同样是{左闭右开)区间
clear();

*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;

    // 尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // 遍历
    printVector(v1);

    // 尾删法
    v1.pop_back();
    printVector(v1);

    // 插入1：第一个参数是迭代器
    v1.insert(v1.begin(), 100);
    printVector(v1);

    // 插入2：插入count个elem
    v1.insert(v1.begin(), 2, 2000); // insert的重载版本
    printVector(v1);

    // 删除1：指定位置删除，第一个参数是迭代器
    v1.erase(v1.begin());
    printVector(v1);

    // 删除2：指定区间删除，注意同样是{左闭右开)区间
    v1.erase(v1.begin() + 1, v1.end() - 1);
    printVector(v1);

    // 清空
    v1.clear();
    printVector(v1);
}

int main()
{
    test01();
    return 0;
}