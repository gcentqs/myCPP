#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    virtual
    void func()
    {
        cout << "Base::func()" << endl;
    }
private:
    double base;
};

class Derived
: virtual public Base
{
public:
    void func() override
    {
        cout << "Derived::func()" << endl;
    }
    virtual void func2()
    {

    }
private:
    double derived;
};

int main()
{
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
    Derived derived;
    printf("Derived虚表的地址 = %p\n", *(long *)(&derived));
}
