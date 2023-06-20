#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector容量和大小

功能：
对vector容器的容量和大小操作
vector作为动态，可以动态扩展，由STL的vector类自动给出

要明白，vector作为类模板，在创建对象之后，其成员函数的调用都是通过对象名加.来访问的。操作符的重载也是对象名+操作符

函数原型（vector类模板中的函数声明）
empty();         // 判断容器是否为空
capacity();      // 容器的容量
size();          // 返回容器中元素的个数
// 容量始终是大于等于size的，所以如果resize的长度超过capacity后，capacity也会相应变得更大，由STL的vector算法自动给出
resize(int num); // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置，默认值对于int可能是0
                 // 如果容器变短，则末尾超出容器长度的元素被删除
resize(int num, elem); // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置
                 // 如果容器变短，则末尾超出容器长度的元素被删除

                 //如果resize之后总的size变小了，但容器的容量capacity是不会发生变化的
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

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    if (v1.empty()) // 为真 代表容器为空
    {
        cout << "v1容器为空" << endl;
    }
    else
    {
        cout << "v1容器不为空" << endl;
    }

    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;

    // 重新指定大小，扩充则补默认值，缩小则删除末尾值
    v1.resize(18); // size超过capacity后，capacity会自动扩容，无需自己指定
    cout << "----resize(18)之后：----" << endl;
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;

    // 重新指定大小，并指定扩充的默认值
    v1.resize(20, 500);
    cout << "----resize(20,500)之后：----" << endl;
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;

    // 重新指定大小，扩充则补默认值，缩小则删除末尾值
    v1.resize(5);
    cout << "----resize(5)之后：----" << endl;
    printVector(v1);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;
}

int main()
{
    test01();
    return 0;
}