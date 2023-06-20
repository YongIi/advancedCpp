#include <iostream>
#include <string>
using namespace std;

// 测试回调函数

void func1()
{
    cout << "调用func1" << endl;
}

template <typename T>
void func2(int a, T func)
{
    cout << "第一个参数：" << a << endl;
    func();
}

int main()
{
    func2(3, func1);

    return 0;
}