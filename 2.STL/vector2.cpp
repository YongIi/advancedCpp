#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector赋值操作

函数原型（vector类模板中的函数声明）
vector& operator=(const vector &vec);  // 重载=操作符，即可以用=号直接进行容器间的赋值
assign(beg, end);  // 将[beg, end)区间中的数据拷贝赋值给本身
assign(n,elem);    // 将n个elem拷贝赋值给本身

*/

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// vector赋值
void test01()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    // 赋值一：operator=
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    // 赋值二：assign(beg, end);
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());  //左闭又开
    printVector(v3);

    // 赋值三：assign(n,elem);
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main()
{
    test01();
    return 0;
}