#include <string.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(new char[1 + 4]() + 4)
    {
        cout << "String()" << endl;
        initRefcount();
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefcount();
    }

    String(const String &rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(const String &)" << endl;
        increaseRefcount();
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String)" << endl;
        if (this != &rhs)
        {
            release();
            _pstr = rhs._pstr;
            increaseRefcount();
        }
        return *this;
    }
    char &operator[](size_t idx)
    {
        if (idx < size())
        {
            if (getRefcount() > 1)
            {
                char *ptmp = new char[size() + 5]() + 4; 
                strcpy(ptmp, _pstr);
                decreaseRefcount();
                _pstr = ptmp;
                initRefcount();
            }
            return _pstr[idx];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }
    size_t size() const 
    {
        return strlen(_pstr);
    }
    ~String()
    {
        cout << "~String()" << endl;
        release();
    }
public:
    int getRefcount() const
    {
        return *(int *)(_pstr - 4);
    }
    const char *c_str() const
    {
        return _pstr;
    }
private:
    void release()
    {
        decreaseRefcount();
        if (0 == getRefcount())
        {
            delete [] (_pstr - 4);
            cout << "delete heap data" << endl;
        }
    }
    void initRefcount()
    {
        *(int *)(_pstr - 4) = 1;
    }
    void increaseRefcount()
    {
        ++*(int *)(_pstr - 4);
    }
    void decreaseRefcount()
    {
        --*(int *)(_pstr - 4);
    }
    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
};
std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if (rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

void test()
{
    String s1("hello");
    String s2 = s1;
    cout << "s1 = " << s1 << ", refcount = " << s1.getRefcount() << endl
         << "s2 = " << s2 << ", refcount = " << s2.getRefcount() << endl;
    printf("s1 addr = %p\n", s1.c_str());
    printf("s2 addr = %p\n", s2.c_str());

    cout << endl << endl;
    String s3("world");
    cout << "s3 = " << s3 << ", refcount = " << s3.getRefcount() << endl;
    printf("s3 addr = %p\n", s3.c_str());
    cout << "s3 = s1" << endl;
    s3 = s1;
    cout << "s3 = " << s3 << ", refcount = " << s3.getRefcount() << endl;
    printf("s3 addr = %p\n", s3.c_str());

    cout << "s[0] = 'H'" << endl;
    s3[0] = 'H';
    cout << "s1 = " << s1 << ", refcount = " << s1.getRefcount() << endl
         << "s2 = " << s2 << ", refcount = " << s2.getRefcount() << endl
         << "s3 = " << s3 << ", refcount = " << s3.getRefcount() << endl;
    printf("s1 addr = %p\n", s1.c_str());
    printf("s2 addr = %p\n", s2.c_str());
    printf("s3 addr = %p\n", s3.c_str());

    cout << "s[0] read op" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << ", refcount = " << s1.getRefcount() << endl
         << "s2 = " << s2 << ", refcount = " << s2.getRefcount() << endl
         << "s3 = " << s3 << ", refcount = " << s3.getRefcount() << endl;
    printf("s1 addr = %p\n", s1.c_str());
    printf("s2 addr = %p\n", s2.c_str());
    printf("s3 addr = %p\n", s3.c_str());
}

int main()
{
    test();

    return 0;
}

