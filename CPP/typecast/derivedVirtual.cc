#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A
{
public:
    virtual
    void a()
    {
        cout << "A:a()" << endl;
    }
    
    virtual
    void b()
    {
        cout << "A:b()" << endl;
    }

    virtual
    void c()
    {
        cout << "A:c()" << endl;
    }
};

class B
{
public:
    virtual
    void a()
    {
        cout << "B:a()" << endl;
    }
    
    virtual
    void b()
    {
        cout << "B:b()" << endl;
    }

    /* virtual */
    void c()
    {
        cout << "B:c()" << endl;
    }

    void d()
    {
        cout << "B:d()" << endl;
    }
};

class C
: public A
, public B
{
public:
    void a()
    {
        cout << "C::a()" << endl;
    }

    void c()
    {
        cout << "C::c()" << endl;
    }

    void d()
    {
        cout << "C::d()" << endl;
    }
};

int main()
{
    C c;

    A *pa = &c;
    pa->a();
    pa->b();
    pa->c();
    
    cout << endl;
    B *pb = &c;
    pb->a();
    pb->b();
    pb->c();
    pb->d();

    cout << endl;
    C *pc = &c;
    pc->a();
    /* pc->b();//error! 二义性 */
    pc->A::b();
    pc->B::b();
    pc->c();
    pc->d();

    return 0;
}

