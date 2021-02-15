#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A
{
public:
    A()
    {
        cout << "A()" <<endl;
    }
    A(int ia)
    : _ia(ia)
    {
        cout << "A(int)" << endl;
    }

protected:
    int _ia;
};

class B
: virtual public A
{
public:
    B()
    {
        cout << "B()" <<endl;
    }
    B(int ia, int ib)
    : A(ia)
    , _ib(ib)
    {
        cout << "A(int)" << endl;
    }

protected:
    int _ib;
};

class C
: public B
{
public:
    C()
    {
        cout << "C()" << endl;
    }

    C(int ia, int ib, int ic)
    : B(ia, ib)
    , A(ia)
    , _ic(ic)
    {
        cout << "C(int, int, int)" << endl;
    }

    void show() const
    {
        cout << "ia = " << _ia << endl
            << "ib = " << _ib << endl
            << "ic = " << _ic << endl;
    }
    
private:
    int _ic;
};

int main()
{
    C c(10, 20, 30);
    c.show();

    return 0;
}

