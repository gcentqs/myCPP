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

    Base(double base)
    : _base(base)
    {
        cout << "Base(double = 0)" << endl;
    }

    void show() const
    {
        cout << "Base::_base = " << _base << endl;
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
    Derived()
    : Base(0)
    , _derived(0)
    {
        cout << "Derived()" << endl;
    }

    Derived(double base, double derived)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(double, double)" << endl;
    }

    void print()
    {
        cout << "Derived::_derived = " << _derived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
    
private:
    double _derived;
};

int main()
{
    Base base(11.11);
    base.show();
    cout << endl;
    Derived derived(22.22, 33.33);
    derived.print();

    cout << endl << "Convert derived class to the base" << endl;//向上转型
    /* base = derived; */
    base.operator=(derived);
    /* base.show(); */
    
    /* Base &ref = derived; */
    /* Base *pbase = &derived; */
    /* pbase->show(); */

    /* derived.operator=(base); */
    /* Derived &ref1 = base; */
    /* Derieved *pder = &base; */

    /* Derived *pDerived1 = static_cast<Derived *>(&base); */
    /* pDerived1->print(); */

    Derived derived2(10, 20);
    /* derived2.print(); */
    /* Base base2(30); */
    /* base2 = derived2; */
    /* base2.show(); */
    Base *pbase2 = &derived2;
    Derived *pDerived2 = static_cast<Derived *>(pbase2);
    pDerived2->print();

    return 0;
}

