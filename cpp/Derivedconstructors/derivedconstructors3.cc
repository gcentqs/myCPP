#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class Base
{
public:
#if 0
    Base()
    : _base(0)
    {
        cout << "Base()" << endl;
    }
#endif
    Base(double base)
    : _base(base)
    {
        cout << "Base(double)" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    double _base;
};

class Derived
: public Base
{
public:
#if 0
    Derived()
    : Base()
    , _derived(0)
    {
        cout << "Derived()" << endl;
    }
#endif
    Derived(double derived)
    : Base(derived)
    , _derived(derived)
    {
        cout << "Derived(double)"<< endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    double _derived;
    Test _tst;
};

int main()
{
    Derived d1(10);

    return 0;
}
