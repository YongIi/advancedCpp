#include <iostream>
#include <string>
using namespace std;

/*
typedef
给已有类型起个别名

在C++中，typedef是一种用来创建类型别名的关键字。它可以将一个已有的类型定义一个新的名字，以方便程序员使用。

语法：
typedef existing_type new_type_name;

举例：
typedef int myInt;
myInt x = 10;  //等价于int x = 10;

查看变量类型：
如果变量为x，
cout << "x的类型是：" << typeid(x).name() << endl;

注意：C++新标准中建议采用using来给类型起别名
在C++中，可以使用using关键字来为类型、命名空间、函数等起一个别名
using 别名 = 原名;

语法：
// 为std::vector<int>起一个别名IntVector  
using IntVector = std::vector<int>;  // 后续的代码中就可以使用IntVector代替std::vector<int>

*/

int main()
{
    typedef int myInt;
    myInt x = 10;
    cout << "x的类型是：" << typeid(x).name() << endl;
    return 0;
}