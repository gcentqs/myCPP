#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base(double base = 0)
    : _base(base)
    {
        cout << "Base(double = 0)" << endl;
    }

    virtual void show() const
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
    /* Derived() */
    /* : Base(0) */
    /* , _derived(0) */
    /* { */
    /*     cout << "Derived()" << endl; */
    /* } */

    Derived(double base = 0, double derived = 0)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(double = 0, double = 0)" << endl;
    }

    //重定义父类的虚函数
    void show() const
    {
        cout << "Derived::_derived= " << _derived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
    
private:
    double _derived;
};

//当一个类定义了虚函数的时候，就会在该类的对象存储布局中产生一个vfptr
//该虚函数指针指向一张虚表，虚表里面存放的是虚函数的入口地址
//当派生类继承该基类时，就会在该派生类的对象存储布局中产生派生类自己的vfptr
//指向派生类自己的虚函数表，对应派生类自己的虚函数入口地址

//虚函数体现动态多态的5个条件
//1. 基类要定义虚函数
//2. 派生类要冲定义虚函数
//3. 定义派生类对象
//4. 基类的指针指向（引用绑定）派生类对象
//5. 基类指针（引用）调用虚函数
void test(Base &base)
{
    base.show();
}

int main()
{
    Base base(11.11);
    base.show();

    cout << endl;

    Derived derived(22.22, 33.33);

    test(base);
    test(derived);
    cout << endl;

    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl; 

    return 0;
}

