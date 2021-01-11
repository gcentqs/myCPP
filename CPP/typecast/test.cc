#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base(double base = 0)
    :_base(base)
    {
        cout << "Base(double = 0)" << endl;
    }
    void print()
    {
        cout << "This is Base " << "_base = " << _base << endl;
    }

private:
    double _base;
};

class Derived
:public Base
{
public:
    Derived(double base = 1)
    : _base(base)
    {
        cout << "Derived(double = 1)" << endl;
    }
    /* void print() */
    /* { */
    /*     cout << "This is Derived " << "_base in Derived = " << _base << endl; */
    /* } */
private:
    double _base;
};

int main()
{
    Derived d;
    d.Base::print();

    Base *pbase = &d;

    return 0;
}

