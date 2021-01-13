#include <string.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *pbase)
    : _pbase(new char[strlen(pbase) + 1]())
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase, pbase);
    }

    virtual
    void print() const
    {
        cout << "Base::_pbase = " << _pbase << endl;
    }

    virtual
    ~Base()
    {
        cout << "~Base()" << endl;
        if (_pbase)
        {
            delete []_pbase;
            _pbase = nullptr;
        }
    }

private:
    char *_pbase;
};

class Derived
: public Base
{
public:
    Derived(const char *pbase, const char *pderived)
    : Base(pbase)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(const char *, const char *)" << endl;
        strcpy(_pderived, pderived);
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
        if (_pderived)
        {
            delete []_pderived;
            _pderived = nullptr;
        }
    }

private:
    char *_pderived;
};

int main()
{
    Base *pbase1 = new Derived("hello", "world");
    pbase1->print();

    /* pbase1->~Base(); */
    delete pbase1;

    return 0;
}

