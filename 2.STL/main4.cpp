#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
Vector容器嵌套容器

解引用后(*it)得到容器数组中的元素(对象)，它的数据类型是<>中指定的数据类型

二维数组：数组中再嵌套一个数组

学习目标：容器中嵌套容器，我们将所有数据进行遍历输出
*/

void test01()
{
    vector<vector<int>> v; // 大容器嵌套小容器

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器，把所有数据遍历一遍
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
    return 0;
}