#include <iostream>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::bind;

int add(int x, int y)
{
    return x + y;
}

class Example
{
public:
    int add(int x, int y)
    {
        return x + y;
    }

    int data = 100;
};

void test()
{
    /* auto f = bind(add, 1, 2); */ 
    std::function<int()> f = bind(add, 1, 2);
    cout << "f() = " << f() << endl;

    Example ex;
    /* auto f2 = bind(&Example::add, &ex, 1, 2); */
    /* cout << "f2() = " << f2() << endl; */
    f = bind(&Example::add, &ex, 1, 2);

    //bind可以绑定数据成员
    f = bind(&Example::data, &ex);
    cout << "f() = " << f() << endl;

    /* auto f3 = bind(add, 1, std::placeholders::_1); */
    std::function<int(int)>f3 = bind(add, 1, std::placeholders::_1);
    cout << "f3(2) = " << f3(2) << endl; 
}

int main()
{
    test();

    return 0;
}

