#include <iostream>
#include <string>
using namespace std;

#include <vector>

/*
vector存放自定义数据类型

容器：存放特定数据类型的数组
迭代器：指向数组元素的指针
vector<数据类型>::iterator it
解引用后(*it)得到容器数组中的元素(对象)，它的数据类型是<>中指定的数据类型

*/

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // cout << "姓名：" << (*it).m_Name << "\t年龄：" << (*it).m_Age << endl;
        cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << endl;
    }
}

// 存放自定义数据类型 指针
void test02()
{
    vector<Person *> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    // 遍历容器
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it)->m_Name << "\t年龄：" << (*it)->m_Age << endl;
    }
}

int main()
{
    test01();
    cout << "-----------\n";
    test02();
    return 0;
}