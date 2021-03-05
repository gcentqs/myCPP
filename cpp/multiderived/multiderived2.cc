#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    void print() const
    {
        cout << "void A::print() const" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B()" << endl;
    }

    void print() const
    {
        cout << "void B::print() const" << endl;
    }

    ~B()
    {
        cout << "~B()" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C()" << endl;
    }

    void print() const
    {
        cout << "void C::print() const" << endl;
    }

    ~C()
    {
        cout << "~C()" << endl;
    }
};

class D
: public A
, public B
, public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }
    void print() const
    {
        cout << "void D::print() const" << endl;
    }
    ~D()
    {
        cout << "~D()" << endl;
    }
};

int main()
{
    D d;
    d.A::print();
    d.B::print(); 
    d.print();
    d.print();

    return 0;
}

