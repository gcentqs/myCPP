#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base(double member = 0)
    : _member(member)
    {
        cout << "Base(double = 0)" << endl;
    }

    void print() const
    {
        cout << "Base::_member = " << _member << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

private:
/* protected: */
    double _member;
};

class Derived
: public Base
{
public:
    Derived(double member1 = 0, double member2 = 0)
    : Base(member1)
    , _member(member2)
    {
        cout << "Derived(double = 0, double = 0)" << endl;
    }

    void print(int x) const
    {
        cout << "x = " << x << endl;
        cout << "_member = " << _member << endl; 
        /* cout << "Base::_member = " << Base::_member << endl; */
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

private:
    double _member;
};

int main()
{
    Derived derived(10, 20);
    derived.Base::print();
    derived.print(1);

    return 0;
}

