#include <stdio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base = 10)
    : _base(base)
    {
        cout << "Base(long = 10)" << endl;
    }

    virtual
    void func1()
    {
        cout << "Base::func1()" << endl;
    }

    virtual
    void func2()
    {
        cout << "Base::func2()" << endl;
    }

    virtual
    void func3()
    {
        cout << "Base::func3()" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base = 10, double dervied = 20)
    : Base(base)
    , _derived(dervied)
    {
        cout << "Derived(long = 10, double = 20)" << endl;
    }

    virtual
    void func1()
    {
        cout << "Derived::func1()" << endl;
    }

    virtual
    void func2()
    {
        cout << "Derived::func2()" << endl;
    }

    virtual
    void func3()
    {
        cout << "Derived::func3()" << endl;
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
    Derived derived(100, 300);
    Base base(100);
    Base *pbase = &derived;

    printf("derived的地址 = %p\n", &derived);
    printf("虚表的地址 = %p\n", (long *)*(long *)&derived);
    printf("虚函数的入口地址 = %p\n", (long *)*(long *)*(long *)&derived);

    typedef void (*Function)();
    Function pf = nullptr;
    pf = (Function)*(long *)*(long *)&derived;
    pf();
    printf("pf = %p\n", pf);
    
    cout << endl;
    pf = (Function)*((long *)*(long *)&derived + 1);
    pf();
    printf("pf = %p\n", pf);

    cout << endl;
    Derived derived1(200, 400);
    printf("derived1的地址 = %p\n", &derived1);
    printf("虚表的地址 = %p\n", (long *)*(long *)&derived1);

    printf("base虚表的地址 = %p\n", (long *)*(long *)&base);
    printf("pbase虚表的地址 = %p\n", (long *)*(long *)pbase);

    return 0;
}

