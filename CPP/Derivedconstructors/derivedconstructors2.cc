#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
#if 1
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
private:
    double _base;
};

class Derived
: public Base
{
public:
#if 1
    Derived()
    : Base(0)
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
private:
    double _derived;
};

int main()
{
    Derived d1(10);

    return 0;
}
