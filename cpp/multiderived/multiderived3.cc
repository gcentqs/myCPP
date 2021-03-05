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

    void setX(double dx)
    {
        _dx = dx;
    }

    void print() const
    {
        cout << "A: _dx = " << _dx << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    double _dx;
};

class B
: virtual public A
{
/* public: */
};

class C
: virtual public A
{
};

class D
: public B
, public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }

    ~D()
    {
        cout << "~D()" << endl;
    }
};

int main()
{
    D d;
    d.A::setX(5);
    d.A::print(); 
    d.B::setX(100);
    d.C::setX(20);
    d.B::print();
    d.C::print();
    d.setX(1);
    d.print();
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;

    return 0;
}

