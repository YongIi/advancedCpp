#include <iostream>
#include <string>
using namespace std;

/*
函数模板案例：实现通用的对数组进行排序的函数

案例描述：
1、利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
2、排序规则从大到小，排序算法为选择排序
2、分别利用char数组和int数组进行测试
*/

// 实现交换的函数模板
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 排序算法
template <typename T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 认定最大值的下标
        for (int j = i + 1; j < len; j++)
        {
            // 认定的最大值比遍历出的数值小时，替换下标
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            // 交换max和i元素
            mySwap(arr[max], arr[i]);
        }
    }
}

// 提供打印数组的模板
template <class T>
void printArr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    // 测试char数组
    char charArr[] = "badcfe";
    int len = sizeof(charArr) / sizeof(char);
    mySort(charArr, len);
    printArr(charArr, len);
}

void test02()
{
    // 测试int数组
    int intArr[] = {7, 5, 1, 3, 9, 2, 4, 6, 8};
    int len = sizeof(intArr) / sizeof(int);
    mySort(intArr, len);
    printArr(intArr, len);
}

int main()
{
    test01();
    test02();
    return 0;
}