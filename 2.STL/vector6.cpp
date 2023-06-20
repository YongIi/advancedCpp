#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector互换容器

功能：
实现两个容器内所有元素进行互换

本质：
容器交换，是地址(指针)交换

函数原型（vector类模板中的函数声明）
swap(vec);  // 将vec与本身的元素互换

实际用途：
巧用swap可以收缩内存空间
vector<int>(v).swap(v);  //解释在代码中

*/
void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// 1、基本用途
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "交换前：" << endl;
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// 2、实际用途：
// 巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的大小为" << v.size() << endl;
    cout << "v的容量为" << v.capacity() << endl;

    v.resize(3);                                 // 重新指定size大小
    cout << "v的大小为" << v.size() << endl;     // size变小了
    cout << "v的容量为" << v.capacity() << endl; // 容量并没有发生变化

    // 巧用swap收缩内存
    vector<int>(v).swap(v); // 目的：收缩容器的capacity
    /*
    解释：
    vector<int>(v)是利用拷贝构造生成的一个匿名对象，它的元素size与v一致，因为只拷贝到v.size()，所以其capacity小
    将该匿名对象vector<int>(v)与大容量的v进行互换，本质是指针互换。
    由此，大容量的容器v换给匿名对象，小容量的容器由匿名对象换给v
    这样，v的容量capacity就缩小了，而大容量的匿名对象在本行运行结束后由系统回收内存
    */
    cout << "v的大小为" << v.size() << endl;     // size变小了
    cout << "v的容量为" << v.capacity() << endl; // 容量并没有发生变化
}

int main()
{
    test01();
    test02();
    return 0;
}