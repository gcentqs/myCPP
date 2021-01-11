#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    : _base(0)
    {
        cout << "Base()" << endl;
    }
private:
    double _base;
};

class Derived
: public Base
{
public:
    Derived(double derived)
    : _derived(derived)
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
