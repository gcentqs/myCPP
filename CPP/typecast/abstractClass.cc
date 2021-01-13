#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
private:
protected://将构造函数设置为protected，该类属于抽象类

    Base()
    {
        cout << "Base()" << endl;
    }
};

class Derived
: public Base
{
public:
    Derived()
    : Base()
    {
        cout << "Derived()" << endl;
    }
};

int main()
{
    Derived derived;

    return 0;
}

