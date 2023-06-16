#include <iostream>
#include <string>
using namespace std;

// 解决方式1：直接包含.cpp源文件。开发时基本是不会这样操作，没有把源文件交给别人看的
// #include "Person.cpp"
// 解决方式2：将声明.h和实现.cpp写到同一个文件中，并更改后缀名为.hpp。hpp是约定的名称，并不是强制的
#include "Person.hpp"

/*
类模板分文件编写问题及解决

分文件编写的源文件
*/

void test01()
{
    Person<string, int> p("悟空", 1000);
    p.showPerson();
}

int main()
{
    test01();
    return 0;
}