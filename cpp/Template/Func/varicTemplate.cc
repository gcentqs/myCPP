#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename... Args>//Args是模板参数包
void print(Args... args)//args是函数参数包
{
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof...(args) = " << sizeof...(args) << endl;
}

void display()
{
    cout << endl;
}
template <typename T, typename... Args>
void display(T t, Args... args)//...args 打包
{
    cout << t << " ";
    display(args...);//args... 称为解包
}

template <class T>
T sum(T t)
{
    return t;
}
template<class T, class ...Types>
T sum(T t, Types ...types)
{
    return t + sum(types...);
}

void test3()
{
    cout << "sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = " << 
            sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl; 
}

void test()
{
    string s1 = "world";
    print();
    print(1, 2.3);
    print(1, true, 'c');
    print(true, 2, 3.3, "hello", s1);
}

void test2()
{
    string s1 = "world";
    /* display(); */
    display(1, 2.3);
    display(1, true, 'c');
    display(true, 2, 3.3, "hello", s1);
}

int main()
{
    test3();

    return 0;
}

