#include <iostream>

using std::cin;
using std::cout;
using std::endl;


class Singleton
{
public:
    static Singleton *getInstance()
    {
        if (nullptr == _instanceptr)
        {
            _instanceptr = new Singleton();
        }
        return _instanceptr;
    }
    static void destroy()
    {
        if (_instanceptr)
        {
            delete _instanceptr;
            _instanceptr = nullptr;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
    static Singleton *_instanceptr;

};

Singleton *Singleton::_instanceptr = nullptr;

int main()
{
    Singleton *ps1 = Singleton::getInstance();
    Singleton *ps2 = Singleton::getInstance();
    cout << "ps1 = " << ps1 << endl
         << "ps2 = " << ps2 << endl;

    Singleton::destroy();
    Singleton::destroy();

    return 0;
}

