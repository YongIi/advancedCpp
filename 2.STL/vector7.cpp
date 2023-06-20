#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector预留空间

动态扩展：
并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

功能：
减少vector在动态扩展容量时的扩展次数

函数原型（vector类模板中的函数声明）
reserve(int len);  // 容器预留len个元素长度，预留位置不初始化，元素不可访问


*/

void test01()
{
    vector<int> v;

    // 利用reserve预留空间
    v.reserve(100000);

    int count = 0; // 统计v动态扩展容量的次数
    int *p = NULL;

    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i); // 不断尾插，每当capacity不足时就动态扩展容量

        if (p != &v[0])
        {
            count++;
            p = &v[0];
        }
    }

    cout << "v动态扩展容量的次数为：" << count << endl;
}

int main()
{
    test01();
    return 0;
}