#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    //声明了纯虚函数的类叫抽象类，不能创建对象
    //纯虚函数作为接口
    virtual
    void show() const = 0;

    virtual
    void print() const = 0;
};

class Derived
:public Base
{
public:
    void show() const override
    {
        cout << "void Derived::show() const" << endl;
    }
};

class Derived2
:public Derived
{
public:
    void print() const override
    {
        cout << "void Derived2::print() const" << endl;
    }
};

int main()
{
    /* Base base; */

    /* Derived derived; */
    /* derived.show(); */

    Derived2 derived2;
    derived2.show();
    derived2.print();
    
    cout << endl;
    Base *pbase = &derived2;
    pbase->show();
    pbase->print();

    return 0;
}

